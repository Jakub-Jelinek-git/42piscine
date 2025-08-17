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

int is_correct(int n, int **grid, int *outside){
    printf("is correct?\n");
    int row;
    int column;

    // check if any box is not filled in
    row = n-1;
    while (row >= 0)
    {
        column = n - 1;
        while (column >= 0)
        {
            if (grid[row][column] == 0)
            {
                return 0;
            }
            column--;
        }
        row--;
    }

    int i;
    int j;
    int bigger;
    int bigger_counter;

    i = 0;
    j = 0;
    
    while (i < n)
    {
        j = 0;
        bigger = grid[j][i];
        bigger_counter = 1;
        while (j < n)
        {
            if(grid[j][i] > bigger){
                bigger = grid[j][i];
                bigger_counter++;
            }
            j++;
        }
                    printf("topcolumn %d\n", bigger_counter);

         if (bigger_counter != outside[i])
        {
        return 0;
        }
        i++;
    }
   
    while ( i < n+n )
    {
        j = n -1;
        bigger = grid[j][i - n];
        bigger_counter = 1;
        while (j >= 0)
        {

            if(grid[j][i-n] > bigger){
                bigger = grid[j][i -n];
                bigger_counter++;
            }
            j--;
        }
                            printf("bottomcol %d\n", bigger_counter);

         if (bigger_counter != outside[i])
        {
        return 0;
        }
        i++;
    }
    while ( i < n + n + n )
    {
        j = 0;
        bigger = grid[i -n -n ][j];
        bigger_counter = 1;
        while (j < n)
        {
            if(grid[i -n -n][j] > bigger){
                bigger = grid[i-n-n][j];
                bigger_counter++;
            }
            j++;
        }

         if (bigger_counter != outside[i])
        {
        return 0;
        }
        i++;
    }
    while ( i < n + n + n + n)
    {
        j = n-1;
        bigger = grid[i -n -n -n ][j];
        bigger_counter = 1;
        while (j >= 0)
        {
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
	fill(size, grid, #include <unistd.h>
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
	return (0);
}
outside, 0, 0); // added additional parameters necessary to validate whether it is filled correctly
	print_grid(size, grid);
	return (0);
}

            if(grid[i -n -n -n][j] > bigger){
                bigger = grid[i-n-n-n][j];
                bigger_counter++;
            }
            j--;
        }
                            printf("rightrow %d\n", bigger_counter);

         if (bigger_counter != outside[i])
        {
        return 0;
        }
        i++;
    }
    

    return 1;
}


int is_valid_choice(int n, int **grid, int *outside, int number, int row, int column){
        // check the row contain this number
        int i = 0;
        while(grid[i][column] != number && i < n - 1){
            i++;
        }

        // check if the column contain this number
        int j = 0;
        while(grid[row][j] != number && j < n - 1){
            j++;
        }

        if (i == n -1 && j == n - 1)
        {
           return 1;
        }
    return 0;
}

//fills the gid with 0
int	**fill(int n, int **grid, int *outside, int row, int column)
{
    printf("row %d column %d\n", row, column);

    // if I'm at the end. Check if it is correct
    if (row == n)
    {
        printf("Grid should be filled in...\n");
        return is_correct(n, grid, outside);
    }

    // if I'm at the end of a column, hop on to the next row 
    if (column == n)
    {
        printf("At the end of a column...\n");
        // call fill function again for x++ and y = 0
        return fill(n, grid, outside, row+1, 0);
    }
    

    // if the box is already filled in, move on to the next column
    if (grid[row][column] != 0)
    {
        printf("Value is already filled in... %d\n", grid[row][column]);
        // call fill function again for x and y+1
        return fill(n, grid, outside, row, column+1);
    }
    
    // if it is not filled in, select a value
    printf("Selecting value...\n");
    int value;

    value = n;
    while(value > 0){
        if (is_valid_choice(n, grid, outside, value, row, column))
        {
        // if we were able to find a valid value, fill in grid[x][y] 
        grid[row][column] = value;
        // if filling the rest is successful, we can stop at this value and return 1
        if(fill(n, grid, outside, row, column+1)){
            return 1;
        } else {
            // if filling the rest was not successful, set the value to 0 and continue with a next choice
            grid[row][column] = 0;
        }
        }
    value--;
    }
    

    // if it is not correct, return null
	return 0;
}
