/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:10:53 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/18 17:10:54 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*array;

	i = 0;
	if (min >= max)
		return (NULL);
	array = (int *)malloc((max - min) * 4);
	if (!array)
		return (NULL);
	while (i < max - min)
	{
		array[i] = min + i;
		i++;
	}
	return (array);
}

/*int main(void)
{
    int min = -5;
    int max = -13;
    int size = max - min;
    int i = 0;
    int *new_array = ft_range(min, max);

    if (!new_array)
        return 1;

    printf("Pointer: %p\n", (void *)new_array);

    while (i < size)
    {
        printf("%i\n", new_array[i]);
        i++;
    }

    free(new_array);
    return 0;
}*/
