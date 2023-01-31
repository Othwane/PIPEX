#include "../pipex.h"

int ft_strlen(char *string)
{
    int i;

    i = 0;
    while (string[i])
        i++;
    return (i);
}

int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
        size_t  i;

        i = 0;
        while ((s1[i] || s2[i]) && i < n)
        {
                if (s1[i] != s2[i])
                        return ((unsigned char)s1[i] - (unsigned char)s2[i]);
                i++;
        }
        return (0);
}

char    *ft_strjoin(char *s1, char *s2)
{
        int             i;
        char    *new_s;

        i = 0;
        if (!s1 || !s2)
                return (NULL);
        new_s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
        if (!new_s)
                return (NULL);
        while (*s1)
                new_s[i++] = *s1++;
        while (*s2)
                new_s[i++] = *s2++;
        new_s[i] = '\0';
        return (new_s);
}

char	*ft_strchr(char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != (unsigned char)c)
		i++;
	if (str[i] == (unsigned char)c)
		return ((char *)str + i);
	return (NULL);
}