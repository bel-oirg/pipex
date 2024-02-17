/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:17:04 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/02/17 20:10:17 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 65165

typedef struct s_data
{
	void			*data;
	struct s_data	*next;
}	t_data;

typedef struct s_cmd
{
	struct s_cmd	*next;
	char			**flags;
}	t_cmd;

void	*my_malloc(size_t size, int mode);
char	**ft_split(char *s, char *delim);
char	*ft_strjoin(char *s1, char *s2);

char	*ft_strdup(char *s1);
//parsed
void	get_cmds(int argc, char *argv[], char *envp[], t_cmd **cmd);

//parsed_utils
int		is_it_in(char *str, char c);
int		arr_len(char **splited);
int		ft_strlen(char *str);
char	*my_strstr(char *str, char *to_find);

//vinaya
void	vinaya(int argc, char *argv[], t_cmd *cmd);
int		buddha(t_cmd *cmd);
void	err(int *fd_in, int *fd_out);
void	w_err(char *str);

#endif