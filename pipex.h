#ifndef	PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdlib.h>

typedef	struct s_data {
	int pid;
	int tube[2];
	int f_in;
	int f_out;
	char	**path;
	char 	**cmd1;
	char	**cmd2;
	char	*cmdpath1;
	char	*cmdpath2;
}	t_data;

void	ft_printf(const char *specif, ...);
char    **getpath(char **envp);
char    *findpath(char *command, char **envp);
char	*ft_strchr(char *str, int c);
char	*ft_substr(char *s, int start, int len);
char	*ft_strtrim(char *s1, char *set);

void    childproc(t_data *data, char **argv, char **envp);
void    parentproc(t_data *data, char **argv, char **envp);

int ft_strlen(char *string);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char    *ft_strjoin(char *s1, char *s2);
char    **ft_split(char const *s, char c);
char    **pipesplit(char *s);

#endif
