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

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

// char	*ft_substr(char const *s, unsigned int start, size_t len);
// int		ft_strlen(const char *str);
// char	*ft_strchr(const char *str, int char_checked );
// char	*ft_strdup(const char *s);
// char	*ft_strjoin(char const *s1, char const *s2);
// char	*get_next_line(int fd);
// void	*ft_calloc(size_t count, size_t size);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int char_checked );
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *string);
char    *read_file(int fd, char *buffer );
char    *extract_line(char **buffer);
char    *get_next_line(int fd);


#endif
