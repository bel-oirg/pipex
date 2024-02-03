/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:49:31 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/02/03 17:15:32 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int		arr_len(char **splited)
{
	int	index;

	if (!splited)
		return (0);
	index = 0;
	while (splited[index])
		index++;
	return (index);
}

void	check_args(int argc, char *argv[])
{
	int		fd[2];
	int 	index;
	
	index  = -1;
	(argc < 5) && (perror(ERR_ARGS), exit(0), 0);
	fd[0] = open(argv[1], O_RDONLY);
	(fd[0] < 0) && (perror(ERR_FILES), exit(1), 0);
	close(fd[0]);
	fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	(fd[1] < 0) && (perror(ERR_FILES), exit(1), 0);
	close(fd[1]);
}

char	*my_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (&str[i + j + 1]);
			++j;
		}
		++i;
	}
	return (0);
}

char	*add_path(char **envp, char *cmd)
{
	int	index;
	char	*path;
	char	*out;
	char	**path_v;

	index = -1;
	while(envp[++index])
	{
		path = my_strstr(envp[index], "PATH=");
		if (path)
			break;
	}
	path_v = ft_split(path, ':');
	index = -1;
	while(path_v[++index])
	{
		out = ft_strjoin(path_v[index], "/");
		out = ft_strjoin(out, cmd);
		if (!access(out, X_OK))
			return (out);
	}
	return (NULL);
}


void	get_cmds(int argc, char *argv[], char *envp[], t_cmd **cmd)
{
	int		micro_index;
	char	**splited;
	int		index;
	t_cmd	*head;
	
	index = 1;
	head = my_malloc(sizeof(t_cmd), 1);
	*cmd = head;
	while(++index < argc - 1)
	{
		splited = ft_split(argv[index], ' ');
		if (index == 2)
			(*cmd)->flags = my_malloc(sizeof(char *) * (arr_len(splited) + 2), 1);
		else
			(*cmd)->flags = my_malloc(sizeof(char *) * (arr_len(splited) + 1), 1);
		micro_index = -1;
		while(splited[++micro_index])
		{
			if (!micro_index)
				(*cmd)->flags[micro_index] = add_path(envp, splited[micro_index]);
			else
				(*cmd)->flags[micro_index] = splited[micro_index];
		}
		(*cmd)->flags[micro_index] = NULL;
		(*cmd)->next = NULL;
		if (index < argc - 2)
			(*cmd)->next = my_malloc(sizeof(t_cmd), 1);
		(*cmd) = (*cmd)->next;
	}
	*cmd = head;
}
