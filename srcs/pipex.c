/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:42:51 by omajdoub          #+#    #+#             */
/*   Updated: 2023/02/04 20:07:33 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_strlen(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*pipex;

	pipex = malloc(sizeof(t_data));
	argscheck(argc);
	pipe_fork(pipex);
	if (pipex->pid == 0)
	{
		open_inf(pipex, argv);
		childproc(pipex, argv, envp);
	}
	else
	{
		open_outf(pipex, argv);
		parentproc(pipex, argv, envp);
	}
}
