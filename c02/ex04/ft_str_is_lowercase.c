/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 11:06:33 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/10 11:06:34 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		if (!(*str >= 'a' && *str <= 'z'))
			return (0);
		str++;
	}
	return (1);
}

/*
void test_case(char *input, int expected)
{
    int result = ft_str_is_lowercase(input);
    printf("Input: \"%s\" | Expected: %d | Got: %d | %s\n",
           input,
           expected,
           result,
           (result == expected) ? "✅ PASS" : "❌ FAIL");
}

int main(void)
{
    printf("Testing ft_str_is_lowercase:\n\n");

    test_case("hello", 1);             // Only lowercase
    test_case("world", 1);
    test_case("helloWorld", 0);        // Contains uppercase
    test_case("HELLO", 0);             // All uppercase
    test_case("123", 0);               // Digits
    test_case("!@#", 0);               // Symbols
    test_case("", 1);                  // Empty string
    test_case("lowercase", 1);
    test_case("lowerCase", 0);         // Mixed case
    test_case("newline\n", 0);         // Contains newline
    test_case("space bar", 0);         // Contains space

    return 0;
}*/
