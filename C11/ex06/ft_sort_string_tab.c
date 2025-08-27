/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:20:26 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/27 19:07:08 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	should_swap(char *str1, char *str2)
{
	while (*str1 || *str2)
	{
		if (*str1 > *str2)
			return (1);
		else if (*str1 < *str2)
			return (0);
		str1++;
		str2++;
	}
	return (0);
}

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	sorted;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (tab[i] && tab[i + 1])
		{
			if (should_swap(tab[i], tab[i + 1]))
			{
				sorted = 0;
				swap(&tab[i], &tab[i + 1]);
			}
			i++;
		}
	}
}
/*#include <stdio.h>

int	main(void)
{
	char *tab[] = {NULL};

	int i = 0;

	printf("Before sorting:\n");
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}

	ft_sort_string_tab(tab);

	printf("\nAfter sorting:\n");
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}*/
