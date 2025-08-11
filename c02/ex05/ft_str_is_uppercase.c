/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 11:11:12 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/10 11:11:13 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		if (!(*str >= 'A' && *str <= 'Z'))
			return (0);
		str++;
	}
	return (1);
}

/*
void test_case(char *input, int expected)
{
    int result = ft_str_is_uppercase(input);
    printf("Input: \"%s\" | Expected: %d | Got: %d | %s\n",
           input,
           expected,
           result,
           (result == expected) ? "✅ PASS" : "❌ FAIL");
}

int main(void)
{
    printf("Testing ft_str_is_uppercase:\n\n");

    test_case("HELLO", 1);             // Only uppercase
    test_case("WORLD", 1);
    test_case("HelloWorld", 0);        // Mixed case
    test_case("hello", 0);             // Lowercase only
    test_case("123", 0);               // Digits
    test_case("!@#", 0);               // Symbols
    test_case("", 1);                  // Empty string
    test_case("UPPERCASE", 1);
    test_case("UpperCase", 0);         // Mixed case
    test_case("NEWLINE\n", 0);         // Contains newline
    test_case("SPACE BAR", 0);         // Contains space

    return 0;
}
*/
