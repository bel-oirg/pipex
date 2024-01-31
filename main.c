/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:49:39 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/30 04:13:29 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

void	exec_cmd(t_cmd *cmd, char *argv[])
{
	char	buffer[4444];
	int 	forked;
	int		piped;
	int		fd[2];

	argv = NULL;
	piped = pipe(fd);
	forked = fork();
	if (!forked)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execve(cmd->flags[0], cmd->flags, NULL);
	}
	else
	{
		close(fd[1]);
		read(fd[0], buffer, 15);
		close(fd[0]);
		// write(fd[0], buffer, 15);
		printf("%s\n", buffer);
	}
}

int main(int argc, char *argv[])
{
	t_cmd	*cmd;
	int		index;
	
	cmd = NULL;
	index = -1;
	check_args(argc, argv);
	get_cmds(argc, argv, &cmd);
	exec_cmd(cmd, argv);

}
