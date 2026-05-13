#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(char *tab, int n)
{
	int	i;

	i = 0;

	while (i < n)
	{
		ft_putchar(tab[i]);
		i++;
	}

	if (tab[0] != 10 - n + '0')
	{
		write(1, ", ", 2);
	}
}

void	ft_generate(char *tab, int index, int n)
{
	char	c;

	if (index == n)
	{
		ft_print(tab, n);
		return ;
	}

	if (index == 0)
	{
		c = '0';
	}
	else
	{
		c = tab[index - 1] + 1;
	}

	while (c <= '9')
	{
		tab[index] = c;
		ft_generate(tab, index + 1, n);
		c++;
	}
}

void	ft_print_combn(int n)
{
	char	tab[10];

	ft_generate(tab, 0, n);
}

int	main(void)
{
	ft_print_combn(2);

	return (0);
}