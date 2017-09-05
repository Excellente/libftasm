#include <stdio.h>

int print(char *str, int len);

int main(void)
{
    int ret = print("Zamani0", 6);
    printf("\n%d\n", ret);
    return (0);
}