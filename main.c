/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:49:39 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/02/11 00:42:45 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		h_doc;
	int		pid;
	t_cmd	*cmd;

	cmd = NULL;
	h_doc = check_args(argc, argv);
	get_cmds(argc, argv, envp, &cmd);
	pid = fork();
	(pid < 0) && (perror(ERR_FORK), my_malloc(0, 0));
	(!pid && !h_doc) && (vinaya(argc, argv, cmd), 0);
	(!pid && h_doc) && (vinaya_h(argc, argv, cmd->next), 0);
	(pid) && (wait(NULL), ((h_doc) && (unlink("tmp_f"))), my_malloc(0, 0));
}
