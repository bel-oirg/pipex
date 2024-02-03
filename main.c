/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:49:39 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/02/03 09:26:21 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

void	exec_cmd(t_cmd *cmd, char *argv[], int argc)
{
	int 	forked;
	int		piped;
	int		infile;
	// int		status;
	int		outfile;
	int		fd[2];

	piped = pipe(fd);
	forked = fork();
	if (!forked)
	{
		close(fd[0]);
		infile = open(argv[1], O_RDONLY);
		dup2(infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(infile);
		execve(cmd->flags[0], cmd->flags, NULL);
	}
	else
	{
		// waitpid(forked, &status, 0);
		cmd = cmd->next;
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		outfile = open(argv[argc - 1], O_WRONLY);
		dup2(outfile, STDOUT_FILENO);
		execve(cmd->flags[0], cmd->flags, NULL);
		close(outfile);
		close(fd[0]);
	}
}

int main(int argc, char *argv[], char *envp[])
{
	t_cmd	*cmd;
	int		index;
	
	cmd = NULL;
	index = -1;
	check_args(argc, argv);
	get_cmds(argc, argv, envp, &cmd);
	exec_cmd(cmd, argv, argc);

}
