#include "get_next_line.h"

#define BUFFER_SIZE 1024

//Function to read from the file decriptor and update the buffer
char *read_file(int fd, char *buffer )
{
    char temp_buffer[BUFFER_SIZE + 1];
    ssize_t bytes_read;

    bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
    if (bytes_read <= 0)
        return (NULL);
    temp_buffer[bytes_read] = '\0';
    buffer = ft_strjoin(buffer, temp_buffer);
    return (buffer);
}

// Function to extract the next line from the buffer
char *extract_line(char **buffer)
{
    char *line;
    char *new_buffer;
    int i;
    int j;

    i = 0;
    while ((*buffer)[i] && (*buffer)[i] != '\n')
        i++;
    if (i == 0 && !(*buffer)[i])
    {
        free (*buffer);
        return (NULL);
    }
    line = ft_calloc(i + 2, sizeof(char));
    if (!line)
        return (NULL);
    j = 0;
    while (j < i)
    {
        line[j] = (*buffer)[j];
        j ++; 
    }
    line[i] = '\0';
    new_buffer = ft_strchr(*buffer, '\n')
    if (new_buffer)
    {
        new_buffer++;
        free(*buffer);
        *buffer = ft_strjoin("", new_buffer);
    }
    else
    {
        free (*buffer);
        *buffer = NULL;
    }
    return (line);

}