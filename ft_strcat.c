#include <stdio.h>

char *ft_strcat(char *dest, char *src)
{
    int i;
    int j;

    i = 0;

    // หา end ของ dest
    while (dest[i] != '\0')
    {
        i++;
    }

    j = 0;

    // copy src ต่อท้าย
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }

    // ปิด string
    dest[i] = '\0';

    return (dest);
}

int main(void)
{
    char dest[50] = "Hello ";
    char src[] = "World";

    printf("%s\n", ft_strcat(dest, src));

    return (0);
}