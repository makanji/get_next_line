#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_size;
	char	*res;
	int		i;
	int		j;

	i = 0;
	total_size = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (total_size + 1));
	if (!res || !s1 || !s2)
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