/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 13:05:06 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/16 13:05:07 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// fills the gid with 0
void	fill_full(int size, int **grid, int i)
{
	int	value;

	value = 1;
	while (value <= size)
	{
		if (i < size)
			grid[value - 1][i] = value;
		else if (i < 2 * size)
			grid[size - value][i - size] = value;
		else if (i < 3 * size)
			grid[i - 2 * size][value - 1] = value;
		else
			grid[i - 3 * size][size - value] = value;
		value++;
	}
}

void	fill_one(int size, int **grid, int i)
{
	if (i < size)
		grid[0][i] = size;
	else if (i < 2 * size)
		grid[size - 1][i - size] = size;
	else if (i < 3 * size)
		grid[i - 2 * size][0] = size;
	else
		grid[i - 3 * size][size - 1] = size;
}

int	**pre_fill(int size, int **grid, int *outside)
{
	int	i;

	i = 0;
	while (i < 4 * size)
	{
		if (outside[i] == size)
			fill_full(size, grid, i);
		else if (outside[i] == 1)
			fill_one(size, grid, i);
		i++;
	}
	return (grid);
}