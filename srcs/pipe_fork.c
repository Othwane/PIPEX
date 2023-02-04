/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:44:37 by omajdoub          #+#    #+#             */
/*   Updated: 2023/02/04 19:45:09 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	pipe_fork(t_data *data)
{
	if (pipe(data->tube) == -1)
	{
		ft_printf("pipex: Pipe Error\n");
		exit (1);
	}
	data->pid = fork();
	if (data->pid == -1)
	{
		ft_printf("pipex: Fork Error\n");
		exit (1);
	}
}
