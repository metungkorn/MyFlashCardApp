#include <unistd.h>

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
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
		if (base[i] == '+' || base[i] == '-')
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_number(long nbr, char *base, int base_len)
{
	if (nbr >= base_len)
		print_number(nbr / base_len, base, base_len);

	ft_putchar(base[nbr % base_len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	long	n;

	if (!is_valid_base(base))
		return ;

	base_len = ft_strlen(base);
	n = nbr;

	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}

	print_number(n, base, base_len);
}

int	main(void)
{
	ft_putnbr_base(42, "01");
	write(1, "\n", 1);

	ft_putnbr_base(42, "0123456789");
	write(1, "\n", 1);

	ft_putnbr_base(42, "0123456789ABCDEF");
	write(1, "\n", 1);

	ft_putnbr_base(-42, "0123456789ABCDEF");
	write(1, "\n", 1);

	return (0);
}