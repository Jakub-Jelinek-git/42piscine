/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 09:05:08 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/16 09:05:19 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int		**create_grid(char *str);
int		**fill(int n, int **grid, int *outside, int *coordinates);
int		**pre_fill(int n, int **grid, int *outside);
void	print_grid(int n, int **grid);
int		*outside_nums(char *str, int num_of_nums);
int		get_side_len(int n);
int		get_n_of_numbers(char *str);

// outside stores the nubers in the given string
// we have to calculate this from the input length
// added pre-fill function that populates the grid based on some rules
// added additional parameters necessary to
// validate whether it is filled correctly
int	main(int argc, char **argv)
{
	int	size;
	int	**grid;
	int	*outside;
	int	coordinates_start[2];

	size = 6;
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	coordinates_start[0] = 0;
	coordinates_start[1] = 0;
	grid = create_grid(argv[1]);
	outside = outside_nums(argv[1], get_n_of_numbers(argv[1]));
	pre_fill(size, grid, outside);
	fill(size, grid, outside, coordinates_start);
	print_grid(size, grid);
	free(grid);
	free(outside);
	return (0);
}
