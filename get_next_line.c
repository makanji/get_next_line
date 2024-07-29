#include "get_next_line.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

// static char *expand_buffer(char *buffer, char *temp)
// {
//     char *new_buffer;

//     if (!buffer)
//         return (ft_strdup(temp));
//     new_buffer = ft_strjoin(buffer, temp);
//     free(buffer);
//     return (new_buffer);
// }

static char *expand_buffer(char *buffer, char *temp)
{
	char *new_buffer;

	if (!buffer && !temp)
		return (NULL);
	if (!buffer)
		return (ft_strdup(temp));
	if (!temp)
		return (buffer);
	new_buffer = ft_strjoin(buffer, temp);
	free(buffer);
	return (new_buffer);
}

// static char *read_file(int fd, char *buffer)
// {
//     char *temp;
//     ssize_t bytes_read;

//     temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
//     if (!temp)
//         return (NULL);

//     bytes_read = 1;
//     while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
//     {
//         bytes_read = read(fd, temp, BUFFER_SIZE);
//         if (bytes_read == -1)
//         {
//             free(temp);
//             return (NULL);
//         }
//         temp[bytes_read] = '\0';
//         buffer = expand_buffer(buffer, temp);
//         if (!buffer)
//         {
//             free(temp);
//             return (NULL);
//         }
//     }
//     free(temp);
//     return (buffer);
// }

static char *read_file(int fd, char *buffer)
{
	char *temp;
	ssize_t bytes_read;

	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);

	bytes_read = 1;
	while (bytes_read > 0 && (!buffer || !ft_strchr(buffer, '\n')))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[bytes_read] = '\0';
		buffer = expand_buffer(buffer, temp);
		if (!buffer)
		{
			free(temp);
			return (NULL);
		}
	}
	free(temp);
	return (buffer);
}


static char *extract_line(char *buffer)
{
	char *line;
	int i;

	if (!buffer[0])
		return (NULL);

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;

	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';

	return (line);
}

static char *update_buffer(char *buffer)
{
	char *new_buffer;
	int i, j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!new_buffer)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	free(buffer);
	return (new_buffer);
}

char *get_next_line(int fd)
{
	static char *buffer;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);

	line = extract_line(buffer);
	buffer = update_buffer(buffer);

	return (line);
}
