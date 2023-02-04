/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openfds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:42:12 by omajdoub          #+#    #+#             */
/*   Updated: 2023/02/04 19:44:01 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	open_inf(t_data *data, char **argv)
{
	data->f_in = open(argv[1], O_RDONLY);
	if (data->f_in == -1)
	{
		ft_printf("pipex: %s: No such file or directory\n", argv[1]);
		exit(1);
	}
	if (access(argv[1], F_OK) != 0)
	{
		ft_printf("pipex: %s: No such file or directory\n", argv[1]);
		exit (1);
	}
	if (access(argv[1], R_OK) != 0)
	{
		ft_printf("pipex: %s: Permition denied\n", argv[1]);
		exit (1);
	}
}

void	open_outf(t_data *data, char **argv)
{
	data->f_out = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0664);
	if (data->f_out == -1)
	{
		ft_printf("pipex: %s: failed to open file\n", argv[4]);
		exit (1);
	}
	if (access(argv[4], W_OK) != 0)
	{
		ft_printf("Pipex: %s: Permition denied\n", argv[4]);
		exit (1);
	}
}
