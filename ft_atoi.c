#include <stdio.h>

int ft_atoi(char *str)
{
    int i;
    int sign;
    int result;

    i = 0;
    sign = 1;
    result = 0;

    // 1. skip whitespace
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;

    // 2. check sign
    while (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -sign;
        i++;
    }

    // 3. convert numbers
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return (result * sign);
}

int main(void)
{
    printf("%d\n", ft_atoi("1234"));
    printf("%d\n", ft_atoi("   +1234"));
    printf("%d\n", ft_atoi("   ---+--+1234ab567"));
    printf("%d\n", ft_atoi("-42"));

    return (0);
}