/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 18:31:32 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/09 18:31:33 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	count;

	count = 0;
	while (count < (size / 2))
	{
		temp = tab[count];
		tab[count] = tab[size - 1 - count];
		tab[size - 1 - count] = temp;
		count++;
	}
}

/*int main() {
    int i;
    int tab[] = {1, 3, 4, 5};
    int size = sizeof(tab) / sizeof(tab[0]);

    // Print original array
    printf("Original array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    // Call the reverse function
    ft_rev_int_tab(tab, size);

    // Print reversed array
    printf("Reversed array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    return 0;
}*/
