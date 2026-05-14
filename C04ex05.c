#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
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
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);

	i = 0;
	while (base[i])
	{
		if (base[i] == '+'
			|| base[i] == '-'
			|| is_space(base[i]))
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
	int	i;

	i = 0;
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
	int	i;
	int	sign;
	int	result;
	int	base_len;
	int	value;

	if (!is_valid_base(base))
		return (0);

	i = 0;
	sign = 1;
	result = 0;
	base_len = ft_strlen(base);

	while (is_space(str[i]))
		i++;

	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}

	value = get_value(str[i], base);
	while (value != -1)
	{
		result = result * base_len + value;
		i++;
		value = get_value(str[i], base);
	}

	return (result * sign);
}

int	main(void)
{
	printf("%d\n",
		ft_atoi_base("2A", "0123456789ABCDEF"));

	printf("%d\n",
		ft_atoi_base("101010", "01"));

	printf("%d\n",
		ft_atoi_base("   ---+--+2A", "0123456789ABCDEF"));

	return (0);
}