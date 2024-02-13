/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:49:39 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/02/13 22:02:04 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		h_doc;
	t_cmd	*cmd;

	(1) && (cmd = NULL), (h_doc = check_args(argc, argv));
	get_cmds(argc, argv, envp, &cmd);
	(!h_doc) && (vinaya(argc, argv, cmd), 0);
	(h_doc) && (vinaya_h(argc, argv, cmd->next), 0);
}
