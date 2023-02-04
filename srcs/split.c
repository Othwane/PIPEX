/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:36:08 by omajdoub          #+#    #+#             */
/*   Updated: 2023/02/04 19:05:33 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static	int	count_words(const char *s, char c)
{
	int	i;
	int	wd;

	i = 0;
	wd = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		wd++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (wd);
}

int	wordlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_mini_split(char **str, const char *s, char c, int words)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		str[i] = (char *)malloc(sizeof(char) * (wordlen(s, c) + 1));
		j = 0;
		l = wordlen(s, c);
		while (j < l)
		{
			str[i][j++] = *s;
			s++;
		}
		str[i][j] = '\0';
		i++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		words;

	words = count_words(s, c);
	str = (char **)malloc((words + 1) * (sizeof(char *)));
	if (!str)
		return (NULL);
	str = ft_mini_split(str, s, c, words);
	return (str);
}

char	**pipesplit(char *s)
{
	char	**retu;
	char	separat;
	int		i;

	i = 0;
	separat = ' ';
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			separat = s[i];
			break ;
		}
		i++;
	}
	retu = ft_split(s, separat);
	retu[0] = ft_strtrim(retu[0], " ");
	return (retu);
}
