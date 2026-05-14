#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;

	if (nb < 0)
		return (0);

	i = 0;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}

	return (0);
}

int	main(void)
{
	printf("%d\n", ft_sqrt(25));
	printf("%d\n", ft_sqrt(16));
	printf("%d\n", ft_sqrt(26));
	printf("%d\n", ft_sqrt(-4));

	return (0);
}