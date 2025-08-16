/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:02:29 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/13 10:02:30 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	output;
	int	negative;

	output = 0;
	negative = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		output = output * 10 + (*str - '0');
		str++;
	}
	return (output * negative);
}

/*int main() {
    char *test_cases[] = {
        "   ---+--+1234ab567", // example from your guideline
        "42",
        "   +++---42abc",
        "   -+-+--1000xyz",
        "  -0",
        "   ---+++---",        // no digits, should return 0
        "123abc456",
        "   ",
        "",                   // empty string
        "  +--+--+00123",
    };

    int n_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < n_tests; i++) {
        printf("Input: \"%s\" => Output: %d\n",
		 test_cases[i], ft_atoi(test_cases[i]));
    }

    return 0;
}*/
