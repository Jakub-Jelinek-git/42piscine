/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:12:25 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/21 15:26:17 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
#include <stdio.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*dupe_string(char *str)
{
	char	*dupe;
	int		i;

	i = 0;
	dupe = (char *)malloc(str_len(str) + 1);
	if (!dupe)
		return (NULL);
	while (str[i])
	{
		dupe[i] = str[i];
		i++;
	}
	dupe[i] = '\0';
	return (dupe);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*array;

	array = malloc((ac + 1) * sizeof(*array));
	if (!array)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		array[i].size = str_len(av[i]);
		array[i].str = av[i];
		array[i].copy = dupe_string(av[i]);
		if (!array[i].copy)
			return (NULL);
		i++;
	}
	array[ac].size = 0;
	array[ac].str = 0;
	array[ac].copy = 0;
	return (array);
}

/*int main(int argc, char **argv)
{
    t_stock_str *tab;
    int i;

    tab = ft_strs_to_tab(argc - 1, argv + 1); // skip program name
    if (!tab)
    {
        printf("Allocation failed!\n");
        return (1);
    }

    i = 0;
    while (tab[i].str) // loop until sentinel
    {
        printf("Index %d:\n", i);
        printf("  size = %d\n", tab[i].size);
        printf("  str  = %s\n", tab[i].str);
        printf("  copy = %s\n", tab[i].copy);
        i++;
    }
    return (0);
}*/
