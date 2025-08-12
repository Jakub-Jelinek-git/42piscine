/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:51:40 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/12 12:51:42 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dest;
	unsigned int	len_src;
	unsigned int	i;

	i = 0;
	len_dest = 0;
	len_src = 0;
	while (dest[len_dest])
		len_dest++;
	while (src[len_src])
		len_src++;
	if (size <= len_dest)
		return (size + len_src);
	while (src[i] && i < size - len_dest - 1)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}

/*int main()
{
    char buffer[20];
    unsigned int ret;

    // Test 1: Normal concat within buffer size
    buffer[0] = '\0';
    ret = ft_strlcat(buffer, "Hello", sizeof(buffer));
    printf("Test 1: '%s', return: %u\n", buffer, ret);
	 // Expect "Hello", ret = 5

    // Test 2: Append more to existing string
    ret = ft_strlcat(buffer, " World", sizeof(buffer));
    printf("Test 2: '%s', return: %u\n", buffer, ret);
	 // Expect "Hello World", ret = 11

    // Test 3: Size smaller than current dest length
    ret = ft_strlcat(buffer, "!!!", 5);
    printf("Test 3: '%s', return: %u\n", buffer, ret);
	 // buffer unchanged, ret = 5 (size) + 3 (len_src) = 8

    // Test 4: Exact fit in buffer
    buffer[0] = '\0';
    ret = ft_strlcat(buffer, "123456789012345", sizeof(buffer));
    printf("Test 4: '%s', return: %u\n", buffer, ret);
	 // Expect "123456789012345", ret = 15

    ret = ft_strlcat(buffer, "abc", sizeof(buffer)); 
    printf("Test 4 cont: '%s', return: %u\n", buffer, ret);
	 // buffer might be truncated, ret = 18

    // Test 5: Empty src
    buffer[0] = '\0';
    ret = ft_strlcat(buffer, "", sizeof(buffer));
    printf("Test 5: '%s', return: %u\n", buffer, ret);
	 // Expect "", ret = 0

    // Test 6: Size is zero
    buffer[0] = '\0';
    ret = ft_strlcat(buffer, "Test", 0);
    printf("Test 6: '%s', return: %u\n", buffer, ret);
	 // buffer unchanged, ret = 0 + 4 = 4

    return 0;
}*/
