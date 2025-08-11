/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:51:13 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/10 10:51:19 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		if (!((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')))
			return (0);
		str++;
	}
	return (1);
}


void test_case(char *input, int expected)
{
    int result = ft_str_is_alpha(input);
    printf("Input: \"%s\" | Expected: %d | Got: %d | %s\n",
           input,
           expected,
           result,
           (result == expected) ? "✅ PASS" : "❌ FAIL");
}
		   
int main(void)
{
    printf("Testing ft_str_is_alpha:\n\n");

    test_case("HelloWorld", 1);         // Only alphabetic
    test_case("abcXYZ", 1);             // Only alphabetic
    test_case("Hello123", 0);           // Contains digits
    test_case("42Network", 0);          // Starts with digits
    test_case("!@#$", 0);              // Only symbols
    test_case("hello world", 0);        // Contains space
    test_case("", 1);                   // Empty string - should return 1
    test_case("UpperAndLower", 1);      // Mixed upper and lower case
    test_case("newline\n", 0);          // Contains newline
    test_case("Tab\tChar", 0);          // Contains tab

    return 0;
}
