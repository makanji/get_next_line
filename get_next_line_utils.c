/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makanji <makanji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:37:53 by makanji           #+#    #+#             */
/*   Updated: 2024/07/25 16:29:34 by makanji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_size;
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
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
	while (s2[j] != '\0')
	{
		res[i + j] = s2[j];
		j++;
	}
	res[total_size] = '\0';
	return (res);
}

char	*ft_strchr(const char *str, int char_checked)
{
	char	*string;

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

void	*ft_calloc(size_t count, size_t size)
{
	void	*string;
	size_t	i;

	string = malloc(count * size);
	if (!string)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		((char *)string)[i] = 0;
		i++;
	}
	return (string);
}

size_t	ft_strlen(const char *string)
{
	size_t	i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
