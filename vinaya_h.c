/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vinaya_h.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:54:03 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/02/13 23:05:02 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	get_content(char *argv[])
{
	int		fd_in;
	char	*line;
	char	*content;

	content = NULL;
	while (1)
	{
		write(1, "pipe heredoc> ", 14);
		line = get_next_line(0);
		if (!my_strcmp(line, argv[2]))
			break ;
		content = ft_strjoin(content, line);
		free(line);
	}
	fd_in = open("/tmp/.tmp_f", O_RDWR | O_CREAT | O_TRUNC, 0777);
	write(fd_in, content, ft_strlen(content));
	close(fd_in);
}

void	vinaya_h(int argc, char *argv[], t_cmd *cmd)
{
	int		fd_out;
	int		fd_in;

	get_content(argv);
	fd_in = open("/tmp/.tmp_f", O_RDONLY, 0777);
	unlink("/tmp/.tmp_f");
	fd_out = open(argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT, 0777);
	(fd_in < 0 || fd_out < 0) && (perror(""), my_malloc(0, 0));
	(dup2(fd_in, STDIN_FILENO) < 0) && (perror(""), err(&fd_in, &fd_out), 0);
	close(fd_in);
	(buddha(cmd)) && (err(NULL, &fd_out), 0);
	(dup2(fd_out, STDOUT_FILENO) < 0) && (perror(""), err(NULL, &fd_out), 0);
	close(fd_out);
	execve(cmd->next->flags[0], cmd->next->flags, NULL);
	(perror(""), my_malloc(0, 0), 0);
}
