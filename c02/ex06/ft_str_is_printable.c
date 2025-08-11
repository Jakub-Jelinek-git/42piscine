/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 11:27:13 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/10 11:27:15 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		if (!(*str >= ' ' && *str <= '~'))
			return (0);
		str++;
	}
	return (1);
}

/*
void test_case(char *input, int expected)
{
    int result = ft_str_is_printable(input);
    printf("Input: \"%s\" | Expected: %d | Got: %d | %s\n",
           input,
           expected,
           result,
           (result == expected) ? "✅ PASS" : "❌ FAIL");
}

int main(void)
{
    printf("Testing ft_str_is_printable:\n\n");

    test_case("Hello, World!", 1);          // Printable characters
    test_case("1234567890", 1);              // Digits are printable
    test_case("", 1);                        // Empty string
    test_case("!@#$%^&*()_+-=", 1);         // Printable symbols
    test_case("Hello\nWorld", 0);            // Contains newline (non-printable)
    test_case("Tab\tCharacter", 0);          // Contains tab (non-printable)
    test_case("\x7F", 0);                    // DEL character (non-printable)
    test_case("Space bar ", 1);              // Space is printable
    test_case("Printable~", 1);              // Tilde is printable

    return 0;
} 
*/
