/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:49:39 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/02/10 15:49:06 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		here_doc;
	int		forked;
	t_cmd	*cmd;

	cmd = NULL;
	here_doc = check_args(argc, argv);
	get_cmds(argc, argv, envp, &cmd);
	if (!here_doc)
		vinaya(argc, argv, cmd);
	else
	{
		forked = fork();
		(forked < 0) && (perror(ERR_FORK), my_malloc(0, 0));
		if (!forked)
			(1) && (vinaya_h(argc, argv, cmd->next), my_malloc(0, 0));
		else
			(1) && (wait(NULL), unlink("tmp_f"), my_malloc(0, 0));
	}
}
