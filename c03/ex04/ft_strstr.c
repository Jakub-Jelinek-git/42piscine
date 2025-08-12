/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:22:23 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/12 10:22:25 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	is_in(char	*str, char *to_find)
{
	while (*to_find)
	{
		if (*str != *to_find)
			return (0);
		str++;
		to_find++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	if (!*to_find)
		return (str);
	while (*str)
	{
		if (*str == *to_find && is_in(str, to_find))
			return (str);
		str++;
	}
	return (NULL);
}

/*void print_result(const char *label, char *result) {
	if (result)
		printf("%s: \"%s\"\n", label, result);
	else
		printf("%s: (null)\n", label);
}

int main(void) {
	const char *tests[][2] = {
		{"hello world", "world"},     // match at end
		{"abcdef", "def"},            // match at end
		{"abcabcabc", "abcabc"},      // repeated prefix match
		{"", ""},                     // both empty
		{"test", ""},                 // empty needle
		{"", "needle"},               // empty haystack, non-empty needle
		{"foobar", "bar"},            // match in middle
		{"foobar", "baz"},            // no match
		{"same", "same"},             // full string match
		{"aaaab", "aab"}              // overlapping near end
	};

	int n = sizeof(tests) / sizeof(tests[0]);
	for (int i = 0; i < n; i++) {
		const char *haystack = tests[i][0];
		const char *needle = tests[i][1];

		char *res_std = strstr(haystack, needle);
		char *res_ft = ft_strstr((char *)haystack, (char *)needle);

		printf("Test %d:\n", i + 1);
		printf("  Haystack: \"%s\"\n", haystack);
		printf("  Needle:   \"%s\"\n", needle);
		print_result("  Standard strstr", res_std);
		print_result("  Custom   ft_strstr", res_ft);
		printf("  Match: %s\n\n", (res_std == res_ft 
			|| (res_std && res_ft
			&& strcmp(res_std, res_ft) == 0)) ? "✅" : "❌");
	}

	return 0;
}*/
