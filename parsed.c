/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:49:31 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/02/18 01:48:45 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	my_strcmp(char *s1, char *s2)
{
	if (!*s2 && !s1)
		return (0);
	if (!s2 || !s1)
		return (1);
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	if (*s1 == '\n' && !*s2)
		return (0);
	return (*s1 - *s2);
}

int	check_args(int argc, char *argv[])
{
	int	fd[2];
	int	index;

	index = -1;
	(argc < 5) && (w_err("Err Args < 5"), exit(0), 0);
	fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT, 0777);
	(fd[1] < 0) && (perror("out_file "), exit(1), 0);
	close(fd[1]);
	if (!my_strcmp(argv[1], "here_doc"))
	{
		(argc > 6) && (w_err("Err : Args > 6"), my_malloc(0, 0), 0);
		return (1);
	}
	fd[0] = open(argv[1], O_RDONLY, 0777);
	(fd[0] < 0) && (perror("in_file"), exit(1), 0);
	close(fd[0]);
	return (0);
}

static char	*add_path(char **envp, char *cmd)
{
	int		index;
	char	*path;
	char	*out;
	char	**path_v;

	if (is_it_in(cmd, '/'))
		return (cmd);
	index = -1;
	path = NULL;
	while (envp[++index] && !path)
		path = my_strstr(envp[index], "PATH=");
	(!path) && (w_err("PATH not found"), 0);
	path_v = ft_split(path, ":");
	index = -1;
	while (path_v[++index])
	{
		out = ft_strjoin(path_v[index], "/");
		out = ft_strjoin(out, cmd);
		if (!access(out, X_OK))
			return (out);
	}
	return (NULL);
}

static void	fill_cmds(char **splited, char *envp[], t_cmd **cmd)
{
	int	m_index;

	m_index = -1;
	while (splited[++m_index])
	{
		if (!m_index)
			(*cmd)->flags[m_index] = add_path(envp, splited[m_index]);
		else
			(*cmd)->flags[m_index] = splited[m_index];
	}
	(*cmd)->flags[m_index] = NULL;
	(*cmd)->next = NULL;
}

void	get_cmds(int argc, char *argv[], char *envp[], t_cmd **cmd)
{
	t_cmd	*head;
	char	**splited;
	int		index;

	index = 1;
	head = my_malloc(sizeof(t_cmd), 1);
	*cmd = head;
	while (++index < argc - 1)
	{
		splited = ft_split(argv[index], " \t");
		(*cmd)->flags = my_malloc(sizeof(char *) * (arr_len(splited) + 1), 1);
		fill_cmds(splited, envp, cmd);
		(index < argc - 2) && ((*cmd)->next = my_malloc(sizeof(t_cmd), 1));
		(*cmd) = (*cmd)->next;
	}
	*cmd = head;
}
