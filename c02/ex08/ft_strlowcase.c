/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 11:47:54 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/10 11:47:58 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	char	*original;

	original = str;
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
			*str = *str + 32;
		str++;
	}
	return (original);
}

/*int main(void)
{
    char str1[] = "HELLO WORLD!";
    char str2[] = "Already lowercase";
    char str3[] = "12345!@#ABCdef";
    char str4[] = "";

    printf("Test 1:\nOriginal: 
	\"HELLO WORLD!\"\nResult  : \"%s\"\n\n", ft_strlowcase(str1));
    printf("Test 2:\nOriginal: 
	\"Already lowercase\"\nResult  : \"%s\"\n\n", ft_strlowcase(str2));
    printf("Test 3:\nOriginal: 
	\"12345!@#ABCdef\"\nResult  : \"%s\"\n\n", ft_strlowcase(str3));
    printf("Test 4:\nOriginal: 
	\"\"\nResult  : \"%s\"\n\n", ft_strlowcase(str4));

    return 0;
}*/
