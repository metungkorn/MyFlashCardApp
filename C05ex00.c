#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	result;

	if (nb < 0)
		return (0);

	result = 1;

	while (nb > 0)
	{
		result *= nb;
		nb--;
	}

	return (result);
}

int	main(void)
{
	printf("%d\n", ft_iterative_factorial(5));
	printf("%d\n", ft_iterative_factorial(0));
	printf("%d\n", ft_iterative_factorial(-3));

	return (0);
}