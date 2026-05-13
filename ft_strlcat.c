#include <stdio.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int i = 0;

	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int len_dest;
	unsigned int len_src;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);

	if (size <= len_dest)
		return (size + len_src);

	i = len_dest;
	j = 0;

	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';

	return (len_dest + len_src);
}

int	main(void)
{
	char dest[20] = "Hello";
	char src[] = "World";

	printf("%u\n", ft_strlcat(dest, src, 8));
	printf("%s\n", dest);

	return (0);
}