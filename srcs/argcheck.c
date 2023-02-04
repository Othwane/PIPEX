/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:37:50 by omajdoub          #+#    #+#             */
/*   Updated: 2023/02/04 19:38:19 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	argscheck(int argc)
{
	if (argc != 5)
	{
		ft_printf("pipex: Incompatible arguments\n");
		exit(1);
	}
}
