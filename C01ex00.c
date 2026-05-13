#include <stdio.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

int	main(void)
{
	int	a;

	a = 0;

	printf("ก่อน: %d\n", a);

	ft_ft(&a);

	printf("หลัง: %d\n", a);

	return (0);
}