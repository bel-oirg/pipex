/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsed_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:07:11 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/02/19 15:30:49 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	arr_len(char **splited)
{
	int	index;

	if (!splited)
		return (0);
	index = 0;
	while (splited[index])
		index++;
	return (index);
}

char	*my_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = -1;
	if (!to_find[0])
		return (str);
	while (str[++i])
	{
		j = 0;
		while (str[i + j] && str[i + j] == to_find[j])
		{
			if (!to_find[j + 1])
				return (&str[i + j + 1]);
			++j;
		}
	}
	return (0);
}

int	is_it_in(char *str, char c)
{
	while (str && *str)
		if (*str++ == c)
			return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	if (!str || !*str)
		return (0);
	return (1 + ft_strlen(++str));
}
