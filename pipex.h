/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:49:58 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/02/07 22:33:29 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 1

# define ERR_FILES "[-] Invalid files\n"
# define ERR_MAL "[-] Error on malloc\n"
# define ERR_DUP "[-] Error on dup2\n"
# define ERR_ARGS "[-] Invalid args\n"
# define ERR_PIPE "[-] Error on pipe\n"
# define ERR_FORK "[-] Error on fork\n"
# define ERR_EXEC "[-] Error on execve\n"

typedef struct s_data
{
	void			*data;
	struct s_data	*next;
}	t_data;

typedef struct s_cmd
{
	struct s_cmd	*next;
	char			**flags;
	int				fd_out;
	int				fd_in;
}	t_cmd;

void	*my_malloc(size_t size, int mode);
char	**ft_split(char *s, char c);
// char	*ft_strjoin(char *s1, char *s2);

//parsed
void	get_cmds(int argc, char *argv[], char *envp[], t_cmd **cmd);
char	*check_args(int argc, char *argv[]);
int		my_strcmp(char *s1, char *s2);

//parsed_utils
int		is_it_in(char *str, char c);
int		arr_len(char **splited);
char	*my_strstr(char *str, char *to_find);

//next_line
size_t	ft_strlen(const char *s);
void	free_out(char *out_free);
char	*ft_strjoin(char *s1, char *s2);
int		have_n(char	*temp);
char	*print_line(char **temp);
char	*get_next_line(int fd);

#endif