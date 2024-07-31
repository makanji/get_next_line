#include "get_next_line.h"
int main()
{
    int fd = open("text", O_RDWR);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }
    char *str;
    str = get_next_line(fd);
    while ((str = get_next_line(fd)) != NULL)
    {
        printf("%s\n", str);
        free(str);
    }
    free(str);
    close(fd);
    return 0;
}
