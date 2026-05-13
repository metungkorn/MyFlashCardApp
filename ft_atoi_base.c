#include <stdio.h>

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	is_valid_base(char *base)
{
	int i;
	int j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);

	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || is_space(base[i]))
			return (0);

		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	get_value(char c, char *base)
{
	int i = 0;

	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int i = 0;
	int sign = 1;
	int result = 0;
	int base_len;
	int val;

	if (!is_valid_base(base))
		return (0);

	base_len = ft_strlen(base);

	// skip spaces
	while (is_space(str[i]))
		i++;

	// sign
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}

	// convert
	while (str[i])
	{
		val = get_value(str[i], base);
		if (val == -1)
			break;

		result = result * base_len + val;
		i++;
	}

	return (result * sign);
}

int	main(void)
{
	printf("%d\n", ft_atoi_base("42", "0123456789"));
	printf("%d\n", ft_atoi_base("2A", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("1010", "01"));
	printf("%d\n", ft_atoi_base("   --+2A", "0123456789ABCDEF"));

	return (0);
}