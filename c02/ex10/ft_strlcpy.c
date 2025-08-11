/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 13:38:14 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/10 13:38:15 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (src[i] && i < size -1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

/*int main(void)
{
    char buffer[10];
    unsigned int ret;

    // Test 1: Normal copy, no truncation
    ret = ft_strlcpy(buffer, "Hello", sizeof(buffer));
    printf("Test 1: \"%s\" (ret = %u)\n", buffer, ret);

    // Test 2: Truncation occurs (source longer than buffer)
    ret = ft_strlcpy(buffer, "Hello, World!", sizeof(buffer));
    printf("Test 2: \"%s\" (ret = %u)\n", buffer, ret);

    // Test 3: size = 0, no write, just returns length of src
    ret = ft_strlcpy(buffer, "NoCopy", 0);
    printf("Test 3: buffer unchanged (ret = %u)\n", ret);

    // Test 4: Exact fit (size equals src length + 1)
    ret = ft_strlcpy(buffer, "123456789", sizeof(buffer));
    printf("Test 4: \"%s\" (ret = %u)\n", buffer, ret);

    // Test 5: Empty src string
    ret = ft_strlcpy(buffer, "", sizeof(buffer));
    printf("Test 5: \"%s\" (ret = %u)\n", buffer, ret);

    return 0;
}*/
