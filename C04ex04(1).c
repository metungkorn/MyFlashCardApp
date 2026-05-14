#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
		if (base[i] == '+' || base[i] == '-'
			|| (base[i] >= 9 && base[i] <= 13)
			|| base[i] == ' ')
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

void	ft_putnbr_base(int nbr, char *base)
{
	long	n;
	int		base_len;

	if (!is_valid_base(base))
		return;

	base_len = ft_strlen(base);
	n = nbr;

	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}

	if (n >= base_len)
		ft_putnbr_base(n / base_len, base);

	ft_putchar(base[n % base_len]);
}

int	main(void)
{
	ft_putnbr_base(42, "0123456789");
	write(1, "\n", 1);

	ft_putnbr_base(42, "01");
	write(1, "\n", 1);

	ft_putnbr_base(255, "0123456789ABCDEF");
	write(1, "\n", 1);

	ft_putnbr_base(-42, "poneyvif");
	write(1, "\n", 1);

	return (0);
}