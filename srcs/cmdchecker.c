/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:55:55 by omajdoub          #+#    #+#             */
/*   Updated: 2023/02/09 00:53:07 by omajdoub         ###   ########.fr       */
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

char	*joinslash_cmd(char *envsplited, char *cmd)
{
	char	*command;
	char	*slash;

	slash = ft_strjoin(envsplited, "/");
	command = ft_strjoin(slash, cmd);
	free(slash);
	free(envsplited);
	return (command);
}

char	*checkcmd(char **envp, char **envsplited, char *cmd)
{
	int		i;
	char	*command;

	i = 0;
	envsplited = getpath(envp);
	while (envsplited[i])
	{
		command = joinslash_cmd(envsplited[i], cmd);
		if (access(command, F_OK) == 0)
		{
			free(envsplited);
			return (command);
		}
		i++;
		free(command);
	}
	free(envsplited);
	return (0);
}

char	*findpath(char *cmd, char **envp)
{
	int		i;
	char	**envsplited;
	char	*command;

	i = 0;
	envsplited = NULL;
	command = NULL;
	if (ft_strchr(cmd, '/'))
	{
		if (!access(cmd, F_OK))
			return (cmd);
	}
	command = checkcmd(envp, envsplited, cmd);
	return (command);
}
