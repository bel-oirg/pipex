/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vinaya_h.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:54:03 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/02/17 22:14:27 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*random_f(void)
{
	char	*file_name;
	int		file_len;
	int		fd_rd;
	int		fd_tmp;

	file_len = 16;
	file_name = my_malloc(file_len + 1, 1);
	fd_rd = open("/dev/urandom", O_RDONLY, 0777);
	if (fd_rd < 0)
		return (perror("cannot open /dev/urandom"), random_f());
	read(fd_rd, file_name, file_len);
	close(fd_rd);
	file_name[file_len] = 0;
	fd_tmp = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd_tmp < 0)
		return (random_f());
	close(fd_tmp);
	unlink(file_name);
	return (file_name);
}

static void	fill_file(char *argv[], char *file_name)
{
	char	*line;
	char	*content;
	int		fd_file;

	content = NULL;
	while (1)
	{
		write(1, "pipe heredoc> ", 14);
		line = get_next_line(0);
		if (!my_strcmp(line, argv[2]))
		{
			(1) && (free(line), line = NULL);
			break ;
		}
		content = ft_strjoin(content, line);
		(line) && (free(line), 0);
	}
	fd_file = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0777);
	(fd_file < 0) && (perror("open"), my_malloc(0, 0), 0);
	write(fd_file, content, ft_strlen(content));
	close(fd_file);
}

void	vinaya_h(int argc, char *argv[], t_cmd *cmd)
{
	int		fd_out;
	int		fd_in;
	char	*file_name;

	file_name = random_f();
	fill_file(argv, file_name);
	fd_in = open(file_name, O_RDONLY, 0777);
	(fd_in < 0) && (perror("open"), my_malloc(0, 0));
	unlink(file_name);
	fd_out = open(argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT, 0777);
	(fd_out < 0) && (perror("open"), err(&fd_in, NULL), 0);
	if (dup2(fd_in, STDIN_FILENO) < 0)
		(perror("dup2"), err(&fd_in, &fd_out), 0);
	close(fd_in);
	(buddha(cmd)) && (err(NULL, &fd_out), 0);
	if (dup2(fd_out, STDOUT_FILENO) < 0)
		(perror("dup2"), err(NULL, &fd_out), 0);
	close(fd_out);
	execve(cmd->next->flags[0], cmd->next->flags, NULL);
	w_err("Command not found");
}
