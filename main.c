/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:49:39 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/02/04 21:30:35 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	buddha(t_cmd *cmd)
{
	int	piped;
	int	fd[2];
	int	forked;

	piped = pipe(fd);
	forked = fork();
	if (!forked)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execve(cmd->flags[0], cmd->flags, NULL);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(forked, NULL, 0);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_cmd	*cmd;
	int		index;
	int		fd_in;
	int		fd_out;

	index = 2;
	cmd = NULL;
	check_args(argc, argv);
	get_cmds(argc, argv, envp, &cmd);
	fd_in = open(argv[1], O_RDONLY, 0777);
	fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(fd_in, STDIN_FILENO);
	while(++index  < argc - 1)
		buddha(cmd),
		cmd = cmd->next;
	dup2(fd_out, STDOUT_FILENO);
	execve(cmd->flags[0], cmd->flags, NULL);
}
