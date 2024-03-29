/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:49:31 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/02/19 13:30:01 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
