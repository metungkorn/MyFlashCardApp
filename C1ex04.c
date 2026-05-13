#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp_a;
	int	temp_b;

	temp_a = *a;
	temp_b = *b;

	if (temp_b == 0)
		return;

	*a = temp_a / temp_b;
	*b = temp_a % temp_b;
}

int	main(void)
{
	int	x;
	int	y;

	x = 10;
	y = 3;

	printf("ก่อน: x = %d, y = %d\n", x, y);

	ft_ultimate_div_mod(&x, &y);

	printf("หลัง: x = %d, y = %d\n", x, y);

	return (0);
}