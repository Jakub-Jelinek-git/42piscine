/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:59:01 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/10 10:59:03 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

/*
void test_case(char *input, int expected)
{
    int result = ft_str_is_numeric(input);
    printf("Input: \"%s\" | Expected: %d | Got: %d | %s\n",
           input,
           expected,
           result,
           (result == expected) ? "✅ PASS" : "❌ FAIL");
}

int main(void)
{
    printf("Testing ft_str_is_numeric:\n\n");

    test_case("123456", 1);            // Only digits
    test_case("0000", 1);              // Leading zeros
    test_case("", 1);                  // Empty string
    test_case("42school", 0);          // Mixed digits + letters
    test_case("abc123", 0);            // Letters + digits
    test_case("123 456", 0);           // Digits + space
    test_case("123!", 0);              // Digits + punctuation
    test_case("9", 1);                 // Single digit
    test_case("12\n34", 0);            // Newline in string
    test_case("１２３", 0);             // Full-width digits (not ASCII)

    return 0;
}
*/
