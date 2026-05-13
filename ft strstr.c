#include <stdio.h>

char *ft_strstr(char *str, char *to_find)
{
    int i;
    int j;

    if (to_find[0] == '\0')
        return (str);

    i = 0;

    while (str[i] != '\0')
    {
        j = 0;

        while (str[i + j] == to_find[j] && str[i + j] != '\0')
        {
            if (to_find[j + 1] == '\0')
                return (&str[i]);

            j++;
        }

        i++;
    }

    return (NULL);
}

int main(void)
{
    char str[] = "hello world";
    char find[] = "world";

    char *res = ft_strstr(str, find);

    if (res)
        printf("%s\n", res);
    else
        printf("not found\n");

    return (0);
}