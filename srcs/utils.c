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

char	*ft_strtrim(char *s1, char *set)
{
	char	*str;
	int	len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	if (!set || !s1)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (len > 0 && ft_strchr(set, s1[len - 1]))
		len--;
	str = ft_substr(s1, i, len - i);
	return (str);
}
char	*ft_substr(char *s, int start, int len)
{
	char	*p;
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	if (ft_strlen(s) < len)
		len = ft_strlen(s) - start;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (len > 0 && s[start + i])
	{
		p[i] = s[start + i];
		i++;
		len--;
	}
	p[i] = '\0';
	return (p);
}