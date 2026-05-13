#include <stdio.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
    unsigned int i;
    unsigned int src_len;

    src_len = 0;

    while (src[src_len] != '\0')
    {
        src_len++;
    }

    if (size > 0)
    {
        i = 0;

        while (src[i] != '\0' && i < size - 1)
        {
            dest[i] = src[i];
            i++;
        }

        dest[i] = '\0';
    }

    return (src_len);
}

int main(void)
{
    char src[] = "Hello";
    char dest[10];
    unsigned int result;

    result = ft_strlcpy(dest, src, 4);

    printf("dest = %s\n", dest);
    printf("src length = %u\n", result);

    return (0);
}