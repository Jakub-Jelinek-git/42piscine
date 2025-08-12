/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:50:23 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/09 20:50:24 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*dest_original;

	dest_original = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest_original);
}

/*int main(void)
{
	char source[] = "42 Network";
	char destination[100];

	char *result = ft_strcpy(destination, source);

	printf("Source: %s\n", source);
	printf("Returned pointer points to: %s\n", result);

	return 0;
}*/
