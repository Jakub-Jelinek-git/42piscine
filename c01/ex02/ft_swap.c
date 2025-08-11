/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:26:05 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/08 10:26:26 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

/*int main(void)
{
    int x = 5;
    int y = 10;

    printf("Before: x = %d, y = %d\n", x, y);
    ft_swap(&x, &y);
    printf("After:  x = %d, y = %d\n", x, y);

    return 0;
}*/
