#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b == 0)
		return;

	*div = a / b;
	*mod = a % b;
}

int	main(void)
{
	int	a;
	int	b;
	int	division;
	int	modulo;

	a = 10;
	b = 3;

	ft_div_mod(a, b, &division, &modulo);

	printf("div = %d\n", division);
	printf("mod = %d\n", modulo);

	return (0);
}