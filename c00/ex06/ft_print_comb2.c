/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:34:39 by jjelinek        #+#    #+#               */
/*   Updated: 2025/08/07 16:37:45 by jjelinek       ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_num(char aa, char ab, char ba, char bb)
{
	if (!(aa == '9' && ab == '8' && ba == '9' && bb == '9'))
	{
		write(1, &aa, 1);
		write(1, &ab, 1);
		write(1, " ", 1);
		write(1, &ba, 1);
		write(1, &bb, 1);
		write(1, ", ", 2);
	}
	else
	{
		write(1, &aa, 1);
		write(1, &ab, 1);
		write(1, " ", 1);
		write(1, &ba, 1);
		write(1, &bb, 1);
	}
}

void	ft_inner_loop(char aa, char ab, char ba, char bb)
{
	while (ba <= '9')
	{
		while (bb <= '9')
		{
			ft_print_num(aa, ab, ba, bb);
			bb++;
		}
		bb = '0';
		ba++;
	}
}

void	ft_print_comb2(void)
{
	char	aa;
	char	ab;
	char	ba;
	char	bb;

	aa = '0';
	ab = '0';
	while (aa <= '9')
	{
		while (ab <= '9')
		{
			ba = aa;
			bb = ab + 1;
			ft_inner_loop(aa, ab, ba, bb);
			ab++;
		}
		ab = '0';
		aa++;
	}
}

int	main(void)
{
	ft_print_comb2();
}
