/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 18:52:35 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/09 18:52:37 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

// Declare the reverse function
void	swap(int *int_1, int *int_2)
{
	int	temp;

	temp = *int_1;
	*int_1 = *int_2;
	*int_2 = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	f;

	i = 0;
	while (i < size)
	{
		f = 0;
		while (f < size - 1)
		{
			if (tab[f] > tab[f + 1])
			{
				swap(&tab[f], &tab[f + 1]);
			}
			f++;
		}
		i++;
	}
}

/*int main() {
    int i;
    int tab[] = {10, 3, 41, 5, 100, 1, 3, 10, 9};
    int size = sizeof(tab) / sizeof(tab[0]);

    // Print original array
    printf("Sorted array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    // Call the reverse function
    ft_sort_int_tab(tab, size);

    // Print reversed array
    printf("Sorted array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    return 0;
}*/
