#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(void)
{
	ft_putstr("Hello world!");
	write(1, "\n", 1);

	ft_putstr("42 Bangkok");
	write(1, "\n", 1);

	return (0);
}