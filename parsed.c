/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:49:31 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/02/05 17:17:28 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(int argc, char *argv[])
{
	int	fd[2];
	int	index;

	index = -1;
	(argc < 5) && (perror(ERR_ARGS), exit(0), 0);
	fd[0] = open(argv[1], O_RDONLY, 0777);
	(fd[0] < 0) && (perror(ERR_FILES), exit(1), 0);
	close(fd[0]);
	fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	(fd[1] < 0) && (perror(ERR_FILES), exit(1), 0);
	close(fd[1]);
}

static char	*add_path(char **envp, char *cmd)
{
	int		index;
	char	*path;
	char	*out;
	char	**path_v;

	index = -1;
	while (envp[++index])
	{
		path = my_strstr(envp[index], "PATH=");
		if (path)
			break ;
	}
	path_v = ft_split(path, ':');
	index = -1;
	while (path_v[++index])
	{
		if (is_it_in(cmd, '/'))
			return (cmd);
		out = ft_strjoin(path_v[index], "/");
		out = ft_strjoin(out, cmd);
		if (!access(out, X_OK))
			return (out);
	}
	return (NULL);
}

void	fill_cmds(char **splited, char *envp[], t_cmd **cmd)
{
	int	micro_index;

	micro_index = -1;
	while (splited[++micro_index])
	{
		if (!micro_index)
			(*cmd)->flags[micro_index] = add_path(envp, splited[micro_index]);
		else
			(*cmd)->flags[micro_index] = splited[micro_index];
	}
	(*cmd)->flags[micro_index] = NULL;
	(*cmd)->next = NULL;
}

void	get_cmds(int argc, char *argv[], char *envp[], t_cmd **cmd)
{
	t_cmd	*head;
	char	**splited;
	int		micro_index;
	int		index;

	index = 1;
	head = my_malloc(sizeof(t_cmd), 1);
	*cmd = head;
	while (++index < argc - 1)
	{
		splited = ft_split(argv[index], ' ');
		(*cmd)->flags = my_malloc(sizeof(char *) * (arr_len(splited) + 1), 1);
		micro_index = -1;
		fill_cmds(splited, envp, cmd);
		if (index < argc - 2)
			(*cmd)->next = my_malloc(sizeof(t_cmd), 1);
		(*cmd) = (*cmd)->next;
	}
	*cmd = head;
}
