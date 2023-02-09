/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procmng.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:25:08 by omajdoub          #+#    #+#             */
/*   Updated: 2023/02/09 00:51:25 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	childproc(t_data *data, char **argv, char **envp)
{
	dup2(data->f_in, STDIN_FILENO);
	dup2(data->tube[1], STDOUT_FILENO);
	close(data->tube[0]);
	close(data->tube[1]);
	close(data->f_in);
	data->cmd1 = pipesplit(argv[2]);
	data->cmdpath1 = findpath(data->cmd1[0], envp);
	if (!data->cmdpath1)
	{
		ft_printf("pipex: %s: command not found\n", data->cmd1[0]);
		exit(127);
	}
	if (access(data->cmdpath1, X_OK))
	{
		ft_printf("pipex: %s: Permission denied\n", data->cmd1[0]);
		exit(126);
	}
	execve(data->cmdpath1, data->cmd1, envp);
}

void	parentproc(t_data *data, char **argv, char **envp)
{
	dup2(data->f_out, STDOUT_FILENO);
	dup2(data->tube[0], STDIN_FILENO);
	close(data->tube[0]);
	close(data->tube[1]);
	close(data->f_out);
	data->cmd2 = pipesplit(argv[3]);
	data->cmdpath2 = findpath(data->cmd2[0], envp);
	if (!data->cmdpath2)
	{
		ft_printf("pipex: %s: command not found\n", data->cmd2[0]);
		exit(127);
	}
	if (access(data->cmdpath2, X_OK))
	{
		ft_printf("pipex: %s: Permission denied\n", data->cmd2[0]);
		exit(126);
	}
	execve(data->cmdpath2, data->cmd2, envp);
}
