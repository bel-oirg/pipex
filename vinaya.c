/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vinaya.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:54:32 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/02/11 00:48:16 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	buddha(t_cmd *cmd)
{
	int	fd[2];
	int	forked;

	(pipe(fd) < 0) && (perror(ERR_PIPE), my_malloc(0, 0), 0);
	forked = fork();
	(forked < 0) && (close(fd[0]), close(fd[1]), perror(ERR_FORK), 0);
	if (!forked)
	{
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) < 0)
			(perror(ERR_DUP), my_malloc(0, 0));
		execve(cmd->flags[0], cmd->flags, NULL);
		return (close(fd[1]), perror(ERR_EXEC), my_malloc(0, 0), 0);
	}
	else
	{
		wait(NULL);
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) < 0)
			(perror(ERR_DUP), my_malloc(0, 0), 0);
	}
	return (0);
}

void	err(int *fd_in, int *fd_out)
{
	(fd_in) && (close(*fd_in), 0);
	(fd_out) && (close(*fd_out), 0);
	my_malloc(0, 0);
}

void	vinaya(int argc, char *argv[], t_cmd *cmd)
{
	int		index;
	int		fd_in;
	int		fd_out;

	index = 2;
	fd_in = open(argv[1], O_RDONLY, 0777);
	fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (dup2(fd_in, STDIN_FILENO) < 0)
		(1) && (perror(ERR_DUP), err(&fd_in, &fd_out), 0);
	close(fd_in);
	while (++index < argc - 1)
	{
		(buddha(cmd)) && (err(NULL, &fd_out), 0);
		cmd = cmd->next;
	}
	if (dup2(fd_out, STDOUT_FILENO) < 0)
		(1) && (perror(ERR_DUP), err(NULL, &fd_out), 0);
	close(fd_out);
	execve(cmd->flags[0], cmd->flags, NULL);
	(perror(ERR_EXEC), my_malloc(0, 0), 0);
}
