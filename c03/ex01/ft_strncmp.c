/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:24:07 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/11 17:24:09 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	current;

	current = 0;
	while ((s1[current] || s2[current]) && current < n)
	{
		if (s1[current] != s2[current])
			return ((int)((unsigned char)s1[current])
				- (int)((unsigned char)s2[current]));
		current++;
	}
	return (0);
}

void run_test(char *s1, char *s2, unsigned int n)
{
    int std_result = strncmp(s1, s2, n);
    int ft_result = ft_strncmp(s1, s2, n);

    printf("s1: \"%s\", s2: \"%s\", n: %u\n", s1, s2, n);
    printf("strncmp   : %d\n", std_result);
    printf("ft_strncmp: %d\n", ft_result);
    if ((std_result == 0 && ft_result == 0) 
	|| (std_result < 0 && ft_result < 0) || (std_result > 0 && ft_result > 0))
        printf("✅ PASS\n\n");
    else
        printf("❌ FAIL\n\n");
}

int main(void)
{
    printf("Testing ft_strncmp...\n\n");

    run_test("hello", "hello", 5);
    run_test("hello", "hella", 5);
    run_test("hello", "hella", 4);
    run_test("hello", "hello world", 10);
    run_test("abc", "abcd", 4);
    run_test("abcd", "abc", 4);
    run_test("", "", 1);
    run_test("abc", "", 3);
    run_test("", "abc", 3);
    run_test("abcdef", "abcxyz", 0);
    run_test("abcdef", "abcxyz", 3);
    run_test("abcdef", "abcxyz", 10);
    run_test("same", "same", 0);
    run_test("short", "shorter", 10);

    return 0;
}
