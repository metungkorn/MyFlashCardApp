#include <stdio.h>

char *ft_strncat(char *dest, char *src, unsigned int nb)
{
    unsigned int i;
    unsigned int j;

    i = 0;

    // หา end ของ dest
    while (dest[i] != '\0')
    {
        i++;
    }

    j = 0;

    // copy src ไม่เกิน nb ตัว
    while (src[j] != '\0' && j < nb)
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

    printf("%s\n", ft_strncat(dest, src, 3));

    return (0);
}