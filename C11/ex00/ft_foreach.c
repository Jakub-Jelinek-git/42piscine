/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:23:27 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/27 14:58:10 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
		f(tab[i++]);
}

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// void	ft_putnbr(int n)
// {
// 	if (n >= 10)
// 		ft_putnbr(n / 10);
// 	ft_putchar((n % 10) + '0');
// 	ft_putchar('\n');
// }

// int	main(void)
// {
// 	int	tab[] = {1, 2, 5, 3};
// 	int lenght = 4;
// 	ft_foreach(tab, lenght, ft_putnbr);
// 	return (0);
// }
