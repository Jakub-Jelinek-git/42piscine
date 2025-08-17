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
int		**fill(int n, int **grid, int *outside, int x, int y);
int		**pre_fill(int n, int **grid, int *outside);
void    print_grid(int n, int **grid);
int 	*outside_nums(char *str, int num_of_nums);
int		get_side_len(int n);
int		get_n_of_numbers(char *str);

// outside stores the nubers in the given string
int	main(int argc, char **argv)
{
	int size = 5; // added variable for size, we have to calculate this from the input length
	int	**grid;
	int	*outside;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	
	grid = create_grid(argv[1]);
	outside = outside_nums(argv[1], get_n_of_numbers(argv[1]));
		print_grid(size, grid);

	pre_fill(size, grid, outside); // added pre-fill function that populates the grid based on some rules
	fill(size, grid, outside, 0, 0); // added additional parameters necessary to validate whether it is filled correctly
	print_grid(size, grid);
	free(grid);
	free(nums);
	return (0);
}
