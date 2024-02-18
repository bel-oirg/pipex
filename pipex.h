/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:49:58 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/02/18 21:32:53 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_cmd
{
	struct s_cmd	*next;
	char			**flags;
}	t_cmd;

//my_malloc
typedef struct s_data
{
	void			*data;
	struct s_data	*next;
}	t_data;

void	*my_malloc(size_t size, int mode);

//ft_split
char	**ft_split(char *s, char *delim);

//ft_strjoin
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);

//parsed
void	get_cmds(int argc, char *argv[], char *envp[], t_cmd **cmd);
int		check_args(int argc, char *argv[]);
int		my_strcmp(char *s1, char *s2);

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

//vinaya_h
void	vinaya_h(int argc, char *argv[], t_cmd *cmd);

//next_line
# define BUFFER_SIZE 65165

void	free_out(char *out_free);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		have_n(char	*temp);
char	*print_line(char **temp);
char	*get_next_line(int fd);

#endif