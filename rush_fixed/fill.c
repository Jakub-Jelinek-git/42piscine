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

#include <stdio.h>

// check if any box is not filled in
int	is_correct(int n, int **grid, int *outside)
{
	int	row;
	int	column;
	int	bigger;
	int	bigger_counter;

	row = n - 1;
	while (row >= 0)
	{
		column = n - 1;
		while (column >= 0)
		{
			if (grid[row][column] == 0)
				return (0);
			column--;
		}
		row--;
	}
	row = 0;
	column = 0;
	while (row < n)
	{
		column = 0;
		bigger = grid[column][row];
		bigger_counter = 1;
		while (column < n)
		{
			if (grid[column][row] > bigger)
			{
				bigger = grid[column][row];
				bigger_counter++;
			}
			column++;
		}
		if (bigger_counter != outside[row])
			return (0);
		row++;
	}
	while (row < n + n)
	{
		column = n - 1;
		bigger = grid[column][row - n];
		bigger_counter = 1;
		while (column >= 0)
		{
			if (grid[column][row - n] > bigger)
			{
				bigger = grid[column][row - n];
				bigger_counter++;
			}
			column--;
		}
		if (bigger_counter != outside[row])
			return (0);
		row++;
	}
	while (row < n + n + n)
	{
		column = 0;
		bigger = grid[row - n - n][column];
		bigger_counter = 1;
		while (column < n)
		{
			if (grid[row - n - n][column] > bigger)
			{
				bigger = grid[row - n - n][column];
				bigger_counter++;
			}
			column++;
		}
		if (bigger_counter != outside[row])
			return (0);
		row++;
	}
	while (row < n + n + n + n)
	{
		column = n - 1;
		bigger = grid[row - n - n - n][column];
		bigger_counter = 1;
		while (column >= 0)
		{
			if (grid[row - n - n - n][column] > bigger)
			{
				bigger = grid[row - n - n - n][column];
				bigger_counter++;
			}
			column--;
		}
		if (bigger_counter != outside[row])
			return (0);
		row++;
	}
	return (1);
}

// check the row contain this number
// check if the column contain this number
int	is_valid_choice(int n, int **grid, int number, int *coordinates)
{
	int	i;
	int	j;
	int	row;
	int	column;

	row = coordinates[0];
	column = coordinates[1];
	i = 0;
	while (grid[i][column] != number && i < n - 1)
		i++;
	j = 0;
	while (grid[row][j] != number && j < n - 1)
		j++;
	if (i == n - 1 && j == n - 1)
		return (1);
	return (0);
}

// fills the gid with 0
// if I'm at the end. Check if it is correct
// if I'm at the end of a column, hop on to the next row
// call fill function again for x++ and y = 0
// if the box is already filled in, move on to the next column
// call fill function again for x and y+1
// if it is not filled in, select a value
// if we were able to find a valid value, fill in grid[x][y]
// if filling the rest is successful,
// we can stop at this value and return 1
// if filling the rest was not successful,
// set the value to 0 and continue with a next choice
// if it is not correct, return null
int	**fill(int n, int **grid, int *outside, int *coordinates)
{
	int	row;
	int	column;
	int	value;
	int	new_coords[2];

	row = coordinates[0];
	column = coordinates[1];
	if (row == n)
		return (is_correct(n, grid, outside));
	if (column == n)
	{
		new_coords[0] = row + 1;
		new_coords[1] = 0;
		return (fill(n, grid, outside, new_coords));
	}
	if (grid[row][column] != 0)
	{
		new_coords[0] = row;
		new_coords[1] = column + 1;
		return (fill(n, grid, outside, new_coords));
	}
	value = n;
	while (value > 0)
	{
		if (is_valid_choice(n, grid, value, coordinates))
		{
			grid[row][column] = value;
			new_coords[0] = row;
			new_coords[1] = column + 1;
			if (fill(n, grid, outside, new_coords))
				return (1);
			else
				grid[row][column] = 0;
		}
		value--;
	}
	return (0);
}
