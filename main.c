/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:06:51 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/02/22 10:58:44 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	c_args(int argc, char *argv[])
{
	int	fd[2];

	(argc != 5) && (w_err("Err Args != 5"), 0);
	fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT, 0777);
	(fd[1] < 0) && (perror("out_file"), exit(1), 0);
	close(fd[1]);
	fd[0] = open(argv[1], O_RDONLY, 0777);
	(fd[0] < 0) && (perror("in_file"), unlink(argv[argc - 1]), exit(1), 0);
	close(fd[0]);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_cmd	*cmd;

	cmd = NULL;
	c_args(argc, argv);
	get_cmds(argc, argv, envp, &cmd);
	vinaya(argc, argv, cmd);
}
