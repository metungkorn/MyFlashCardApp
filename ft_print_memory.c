#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_print_hex(unsigned long n, int size)
{
	char	*hex;

	hex = "0123456789abcdef";

	if (size > 1)
	{
		ft_print_hex(n / 16, size - 1);
	}

	ft_putchar(hex[n % 16]);
}

void	ft_print_addr(unsigned long addr)
{
	ft_print_hex(addr, 16);
}

void	ft_print_hex_content(unsigned char *str, unsigned int size)
{
	unsigned int	i;
	char			*hex;

	hex = "0123456789abcdef";
	i = 0;

	while (i < 16)
	{
		if (i < size)
		{
			ft_putchar(hex[str[i] / 16]);
			ft_putchar(hex[str[i] % 16]);
		}
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}

		if (i % 2 == 1)
		{
			ft_putchar(' ');
		}

		i++;
	}
}

void	ft_print_text(unsigned char *str, unsigned int size)
{
	unsigned int	i;

	i = 0;

	while (i < size)
	{
		if (str[i] >= 32 && str[i] <= 126)
		{
			ft_putchar(str[i]);
		}
		else
		{
			ft_putchar('.');
		}

		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)addr;

	while (i < size)
	{
		ft_print_addr((unsigned long)(str + i));
		ft_putstr(": ");

		if (size - i >= 16)
		{
			ft_print_hex_content(str + i, 16);
			ft_print_text(str + i, 16);
		}
		else
		{
			ft_print_hex_content(str + i, size - i);
			ft_print_text(str + i, size - i);
		}

		ft_putchar('\n');

		i += 16;
	}

	return (addr);
}

int	main(void)
{
	char str[] = "Hello\nHow are you?";

	ft_print_memory(str, sizeof(str));

	return (0);
}