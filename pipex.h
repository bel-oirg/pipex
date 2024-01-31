/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:49:58 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/30 02:24:25 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define ERR_ARGS "[-] Invalid args\n"
# define ERR_FILES "[-] Invalid files\n"
# define ERR_MAL "[-] Error on malloc\n"
# define PATH "/bin/"

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
char	**ft_split(char *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);

//parsed
void	get_cmds(int argc, char *argv[], t_cmd	**cmd);
void	check_args(int argc, char *argv[]);
