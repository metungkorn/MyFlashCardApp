#include <unistd.h>
#include <stdio.h>

void	print_solution(int *board)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	is_safe(int *board, int col, int row)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row)
			return (0);

		if ((board[i] - row == i - col)
			|| (board[i] - row == col - i))
			return (0);

		i++;
	}
	return (1);
}

void	solve(int *board, int col, int *count)
{
	int	row;

	if (col == 10)
	{
		print_solution(board);
		(*count)++;
		return ;
	}

	row = 0;
	while (row < 10)
	{
		if (is_safe(board, col, row))
		{
			board[col] = row;
			solve(board, col + 1, count);
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;

	count = 0;
	solve(board, 0, &count);
	return (count);
}

int	main(void)
{
	int	total;

	total = ft_ten_queens_puzzle();

	printf("Total solutions: %d\n", total);

	return (0);
}