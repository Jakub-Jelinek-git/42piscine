/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 09:15:55 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/16 09:15:56 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// returns the number of numbers in the given strings
// non single diget numbers or non numbers throw error
int	get_n_of_numbers(char *str)
{
	int	num_of_nums;
	int	i;

	i = 0;
	num_of_nums = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (str[i + 1] >= '0' && str[i + 1] <= '9' && str[i + 1])
			{
				write(1, "Error: number in parameter is bigger then 9\n", 44);
				return (0);
			}
			num_of_nums++;
		}
		else if (str[i] != ' ')
		{
			write(1, "Error: non number char in the paramter\n", 39);
			return (-1);
		}
		i++;
	}
	return (num_of_nums);
}

// checks if the number of numbers in string can make a sq grid (4x4, 5x5....)
// returns the size of grid side
int	get_side_len(int n)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		if (i * i == n)
		{
			return (i);
		}
		i++;
	}
	if (n >= 0)
		write(1, "Error: wrong number of numbers in string\n", 41);
	return (i);
}

//this function will allocate the memory for grid n x n
int	**allocate_grid(int n)
{
	int	i;
	int	**grid;

	i = 0;
	grid = (int **)malloc(n * 8);
	while (i < n)
	{
		grid[i] = (int *)malloc(n * 4);
		i++;
	}
	return (grid);
}

int	**create_grid(char *str)
{
	int	num_of_ints;
	int	side_len;
	int	**grid;

	num_of_ints = get_n_of_numbers(str);
	side_len = get_side_len(num_of_ints);
	grid = allocate_grid(side_len);
	return (grid);
}

// creates array of ints from the numbers given in param

int *outside_nums(char *str, int num_of_ints)
{
	int *nums;
	int	i;
	int	index_num;

	i = 0;
	index_num = 0;
	nums = (int *)malloc(4 * num_of_ints);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9' && index_num < num_of_ints)
		{
			nums[index_num] = str[i] - '0';
			index_num++;
		}
		i++;
	}
	return (nums);
}
