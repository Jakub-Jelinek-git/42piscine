/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:21:25 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/12 10:21:27 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*origin_dest;
	unsigned int	i;

	i = 0;
	origin_dest = dest;
	while (*dest)
		dest++;
	while (src[i] && i < nb)
	{
		*dest = src[i];
		i++;
		dest++;
	}
	*dest = '\0';
	return (origin_dest);
}

/*int main(void) {
    char dest1[50] = "Hello, ";
    char dest2[50] = "Hello, ";
    char *src = "World!";
    unsigned int n = 10;

    // Using standard strncat
    strncat(dest1, src, n);

    // Using custom ft_strncat
    ft_strncat(dest2, src, n);

    printf("Standard strncat result: %s\n", dest1);
    printf("Custom   ft_strncat result: %s\n", dest2);

    // Optional: test more cases
    char d1[50] = "ABC";
    char d2[50] = "ABC";
    char *s = "123456";
    n = 4;

    strncat(d1, s, n);
    ft_strncat(d2, s, n);

    printf("\nStandard strncat result: %s\n", d1);
    printf("Custom   ft_strncat result: %s\n", d2);

    return 0;
}*/
