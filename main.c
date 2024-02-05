/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:49:39 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/02/05 18:50:39 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	buddha(t_cmd *cmd)
{
	int	fd[2];
	int	forked;

	if (pipe(fd) < 0)
		return (perror(ERR_PIPE), 1);
	forked = fork();
	if (forked < 0)
		return (close(fd[0]), close(fd[1]), perror(ERR_FORK), 1);
	if (!forked)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execve(cmd->flags[0], cmd->flags, NULL);
		return (close(fd[0]), close(fd[1]), perror(ERR_EXEC), 1);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(forked, NULL, 0);
	}
	return (0);
}

void	err(int *fd_in, int *fd_out)
{
	close(*fd_in);
	close(*fd_out);
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
	while (++index < argc - 1)
	{
		(buddha(cmd)) && (err(&fd_in, &fd_out), 0);
		cmd = cmd->next;
	}
	if (dup2(fd_out, STDOUT_FILENO) < 0)
		(1) && (perror(ERR_DUP), err(&fd_in, &fd_out), 0);
	execve(cmd->flags[0], cmd->flags, NULL);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_cmd	*cmd;

	cmd = NULL;
	check_args(argc, argv);
	get_cmds(argc, argv, envp, &cmd);
	vinaya(argc, argv, cmd);
}
