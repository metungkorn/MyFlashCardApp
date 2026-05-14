#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);

	result = 1;

	while (power > 0)
	{
		result *= nb;
		power--;
	}

	return (result);
}

int	main(void)
{
	printf("%d\n", ft_iterative_power(2, 3));
	printf("%d\n", ft_iterative_power(5, 0));
	printf("%d\n", ft_iterative_power(2, -1));

	return (0);
}