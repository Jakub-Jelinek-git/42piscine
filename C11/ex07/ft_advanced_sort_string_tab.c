/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:16:06 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/28 13:36:41 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
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
			if (cmp(tab[i], tab[i + 1]) > 0)
			{
				sorted = 0;
				swap(&tab[i], &tab[i + 1]);
			}
			i++;
		}
	}
}

/*int ft_strcmp(char *s1, char *s2)
{
    while (*s1 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return ((unsigned char)*s1 - (unsigned char)*s2);
}

int rev_cmp(char *s1, char *s2)
{
    return -ft_strcmp(s1, s2); // just flip order
}

void    ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
    write(1, "\n", 1);
}

void    print_tab(char **tab)
{
    int i = 0;
    while (tab[i])
    {
        ft_putstr(tab[i]);
        i++;
    }
    write(1, "-----\n", 6);
}

int main(void)
{
    char *tab1[] = {"banana", "apple", "cherry", "date", 0};
    char *tab2[] = {"banana", "apple", "cherry", "date", 0};

    // normal sort
    ft_advanced_sort_string_tab(tab1, &ft_strcmp);
    print_tab(tab1);

    // reverse sort
    ft_advanced_sort_string_tab(tab2, &rev_cmp);
    print_tab(tab2);

    return 0;
}*/
