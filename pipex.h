/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:51:57 by omajdoub          #+#    #+#             */
/*   Updated: 2023/02/04 20:05:25 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_data {
	int		pid;
	int		tube[2];
	int		f_in;
	int		f_out;
	char	**path;
	char	**cmd1;
	char	**cmd2;
	char	*cmdpath1;
	char	*cmdpath2;
}	t_data;

int		ft_strlen(char *string);
int		ft_strncmp(char *s1, char *s2, int n);
char	**pipesplit(char *s);
char	**ft_split(char const *s, char c);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char *s1, char *set);
char	*ft_substr(char *s, int start, int len);
char	**getpath(char **envp);
char	*findpath(char *cmd, char **envp);
void	childproc(t_data *data, char **argv, char **envp);
void	parentproc(t_data *data, char **argv, char **envp);
void	ft_printf(const char *specif, ...);
void	open_inf(t_data *data, char **argv);
void	open_outf(t_data *data, char **argv);
void	pipe_fork(t_data *data);
void	argscheck(int argc);
#endif
