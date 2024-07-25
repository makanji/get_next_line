#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_size;
	char	*res;
	int		i;
	int		j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	total_size = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (total_size + 1));
	if (!res)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while ( s2[j] != '\0')
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[total_size] = '\0';
	return (res);
}


char    *ft_strchr(const char *str, int char_checked )
{
    char *string;

    string = (char *)str;
    while (*string != '\0')
    {
        if (*string == (char)char_checked)
            return (string);
        string++;
    }
    if (char_checked == '\0')
        return (string);
    return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	char *string;
	size_t i;

	i = 0;
	string = (char *)s;
	while (i < n)
	{
		string[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void *string;
	string = malloc(count * size );
	if (!string)
		return (NULL);
	ft_bzero(string, count * size);
	return (string);
}

size_t	ft_strlen(const char *string)
{
	size_t i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}
