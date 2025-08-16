/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:33:45 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/15 12:33:46 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	result;

	result = 1;
	i = 2;
	if (nb == 0 || nb == 1)
		return (1);
	if (i <= nb)
	{
		while (i <= nb)
		{
			result = result * i;
			i++;
		}
		return (result);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%i", ft_iterative_factorial(atoi(argv[1])));
	return (0);
}
