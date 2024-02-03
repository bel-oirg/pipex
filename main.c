/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:49:39 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/02/03 17:15:05 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	gautama(char *cmd1[], int fd_in, int fd_out)
{
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	execve(cmd1[0], cmd1, NULL);
	close(fd_out);
	close(fd_in);
}

static void	buddha(t_cmd *cmd, int fd_in, int fd_out)
{
	int	piped;
	int	fd[2];
	int	forked;

	piped = pipe(fd);
	forked = fork();
	if (!forked)
	{
		close(fd[0]);
		gautama(cmd->flags, fd_in, fd[1]);
	}
	else
	{
		waitpid(forked, NULL, 0);
		close(fd[1]);
		gautama(cmd->next->flags, fd[0], fd_out);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_cmd	*cmd;
	int		fd_in;
	int		fd_out;

	cmd = NULL;
	check_args(argc, argv);
	get_cmds(argc, argv, envp, &cmd);
	fd_in = open(argv[1], O_RDONLY);
	fd_out = open(argv[argc - 1], O_RDWR);
	buddha(cmd, fd_in, fd_out);
}
