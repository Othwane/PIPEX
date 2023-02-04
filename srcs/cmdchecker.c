/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:55:55 by omajdoub          #+#    #+#             */
/*   Updated: 2023/02/04 18:44:44 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**getpath(char **envp)
{
	int		i;
	char	**tmpath;

	i = 0;
	if (!envp[i])
		tmpath = ft_split("/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin", ':');
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			tmpath = ft_split(envp[i] + 5, ':');
		i++;
	}
	return (tmpath);
}

char	*findpath(char *cmd, char **envp)
{
	int		i;
	char	**envsplited;
	char	*slash;
	char	*command;

	i = 0;
	if (ft_strchr(cmd, '/'))
	{
		if (!access(cmd, F_OK))
			return (cmd);
	}
	else
	{
		envsplited = getpath(envp);
		while (envsplited[i])
		{
			slash = ft_strjoin(envsplited[i], "/");
			command = ft_strjoin(slash, cmd);
			if (access(command, F_OK) == 0)
				return (command);
			i++;
		}
	}
	return (0);
}
