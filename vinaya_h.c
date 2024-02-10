/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vinaya_h.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:54:03 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/02/10 15:51:25 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_input(char *argv[])
{
	char	*line;
	int		fd_in;

	fd_in = open("tmp_f", O_RDWR | O_APPEND | O_CREAT, 0777);
	while (1)
	{
		write(1, "heredoc >>", 11);
		line = get_next_line(0);
		if (!my_strcmp(line, argv[2]))
			break ;
		write(fd_in, line, ft_strlen(line));
		free(line);
	}
	close(fd_in);
}

void	vinaya_h(int argc, char *argv[], t_cmd *cmd)
{
	int		fd_out;
	int		fd_in;

	get_input(argv);
	fd_in = open("tmp_f", O_RDONLY, 0777);
	fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (dup2(fd_in, STDIN_FILENO) < 0)
	{
		close(fd_in);
		(1) && (perror(ERR_DUP), err(&fd_in, &fd_out), 0);
	}
	(buddha(cmd)) && (err(&fd_in, &fd_out), 0);
	if (dup2(fd_out, STDOUT_FILENO) < 0)
		(1) && (perror(ERR_DUP), err(&fd_in, &fd_out), 0);
	execve(cmd->next->flags[0], cmd->next->flags, NULL);
}
