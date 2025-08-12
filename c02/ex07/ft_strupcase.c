/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 11:35:06 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/10 11:39:02 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str)
{
	char	*original;

	original = str;
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
			*str = *str - 32;
		str++;
	}
	return (original);
}

/*int main(void)
{
    char str1[] = "hello world!";
    char str2[] = "already uppercase";
    char str3[] = "12345!@#abcdef";
    char str4[] = "";

    printf("Test 1:\nOriginal: \"hello world!\"\nResult  
	: \"%s\"\n\n", ft_strupcase(str1));
    printf("Test 2:\nOriginal: \"already uppercase\"\nResult
	  : \"%s\"\n\n", ft_strupcase(str2));
    printf("Test 3:\nOriginal: \"12345!@#abcdef\"\nResult
	  : \"%s\"\n\n", ft_strupcase(str3));
    printf("Test 4:\nOriginal: \"\"\nResult  : \"%s\"\n\n",
	 ft_strupcase(str4));

    return 0;
}*/
