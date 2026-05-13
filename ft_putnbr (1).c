#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	n;

	n = nb;

	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}

	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}

	ft_putchar((n % 10) + '0');
}

int	main(void)
{
	ft_putnbr(42);
	ft_putchar('\n');

	ft_putnbr(-42);
	ft_putchar('\n');

	ft_putnbr(0);
	ft_putchar('\n');

	ft_putnbr(2147483647);
	ft_putchar('\n');

	ft_putnbr(-2147483648);
	ft_putchar('\n');

	return (0);
}