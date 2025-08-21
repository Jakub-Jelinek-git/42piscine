/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:25:27 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/21 12:50:31 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	write_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	write_num(int size)
{
	char	c;

	if (size > 9)
		write_num(size / 10);
	c = (size % 10) + '0';
	write(1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		write_str(par[i].str);
		write_num(par[i].size);
		write(1, "\n", 1);
		write_str(par[i].copy);
		i++;
	}
}
