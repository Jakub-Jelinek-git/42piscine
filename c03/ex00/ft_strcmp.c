/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:41:23 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/11 15:41:25 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	current;
	int	value;

	current = 0;
	value = 0;
	while (s1[current] || s2[current])
	{
		if (s1[current] != s2[current])
			return ((int)((unsigned char)s1[current])
				- (int)((unsigned char)s2[current]));
		current++;
	}
	return (0);
}

/*
int main(void)
{
	printf("Test 1: %d\n", ft_strcmp("hello", "hello")); //  0
	printf("Test 2: %d\n", ft_strcmp("abc", "abd")); // negative
	printf("Test 3: %d\n", ft_strcmp("abd", "abc")); // positive
	printf("Test 4: %d\n", ft_strcmp("", "abc")); //negative
	printf("Test 5: %d\n", ft_strcmp("abc", "")); //positive
	return 0;
}*/
