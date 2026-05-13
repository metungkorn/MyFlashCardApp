#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_comb(int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(arr[i] + '0');
		i++;
	}

	// print comma+space except last
	if (arr[0] != 10 - n)
		write(1, ", ", 2);
}

void	generate(int *arr, int n, int idx, int start)
{
	int	i;

	if (idx == n)
	{
		print_comb(arr, n);
		return;
	}

	i = start;
	while (i <= 9)
	{
		arr[idx] = i;
		generate(arr, n, idx + 1, i + 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	arr[10];

	if (n <= 0 || n >= 10)
		return;

	generate(arr, n, 0, 0);
}

int	main(void)
{
	ft_print_combn(2);
	write(1, "\n", 1);

	ft_print_combn(3);
	write(1, "\n", 1);

	return (0);
}