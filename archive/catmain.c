#include <stdio.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <sys/types.h>

int    ft_cat(int fd);

int main(void)
{
    int fd;
    char buff[17];

    buff[16] = '\0';
    fd = open("t", O_RDONLY);
    int ret = ft_cat(fd);
    // printf("%d\n", ret);
    close(fd);
    return (0);
}

// while(read(fd, buff, 16))
// printf("%s", buff);
// printf("\n");