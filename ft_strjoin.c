/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:16:11 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/02/07 21:57:37 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



// static char	*ft_strdup(char *s1)
// {
// 	size_t	len_s1;
// 	int		index;
// 	char	*str;

// 	len_s1 = ft_strlen(s1);
// 	str = my_malloc((len_s1 + 1) * (sizeof(char)), 1);
// 	if (!str)
// 		return (NULL);
// 	index = -1;
// 	while (s1[++index])
// 		str[index] = s1[index];
// 	str[index] = 0;
// 	return (str);
// }

// static char	*one_null(char *s1, char *s2)
// {
// 	if (!s1 && !s2)
// 		return (NULL);
// 	if (s1)
// 		return (ft_strdup(s1));
// 	return (ft_strdup(s2));
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*join;
// 	int		index;
// 	int		index2;

// 	if (!s1 || !s2)
// 		return (one_null(s1, s2));
// 	join = my_malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char), 1);
// 	if (!join)
// 		return (NULL);
// 	index = -1;
// 	while (s1[++index])
// 		join[index] = s1[index];
// 	index2 = -1;
// 	while (s2[++index2])
// 		join[index++] = s2[index2];
// 	join[index] = 0;
// 	return (join);
// }
