// #include "get_next_line.h"
// int main()
// {
//     int fd = open("test.txt", O_RDWR);
//     if (fd == -1)
//     {
//         perror("open");
//         return 1;
//     }
//     char *str;
//     str = get_next_line(fd);
//     while ((str = get_next_line(fd)) != NULL)
//     {
//         printf("%s\n", str);
//         free(str);
//     }
//     free(str);
//     close(fd);
//     return 0;
// }

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
