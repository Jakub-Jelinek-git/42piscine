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

//fills the gid with 0
int	**pre_fill(int n, int **grid, int *outside)
{
    int i;
    int value;
    
    i = 0;
    while (i < n)
    {
        if(outside[i] == n)
        {
                value = 1; //0 is not allowed, we start with 1
                while (value <= n)
                {
                    printf("value %d\n", value);
                    printf("i %d\n", i);
                    grid[value - 1][i] = value;
                    value++;
                }
        }
        if (outside[i] == 1)
        {
            grid[0][i] = n;
        }
        i++;
    }

    while ( i < n+n )
    {
         if(outside[i] == n)
        {
                value = 1; 
                while (value <= n)
                {
                    grid[n - value][i -n] = value;
                    value++;
                }
        }
        if (outside[i] == 1)
        {
            grid[n - 1][i -n] = n;
        }
        i++;
    }
    while ( i < n + n + n )
    {
         if(outside[i] == n)
        {
                value = 1; 
                while (value <= n)
                {
                    grid[i - n -n][value - 1] = value;
                    value++;
                }
        }
        if (outside[i] == 1)
        {
            grid[i - n - n][0] = n;
        }
        i++;
    }
    while ( i < n + n + n + n)
    {
         if(outside[i] == n)
        {
                value = 1; 
                while (value <= n)
                {
                    grid[i - n -n -n][n - value] = value;
                    value++;
                }
        }
        if (outside[i] == 1)
        {
            grid[i - n - n -n][n - 1] = n;
        }
        i++;
    }
    return grid;
}
