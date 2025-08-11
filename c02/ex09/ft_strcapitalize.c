/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 12:25:35 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/10 12:55:33 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	is_alphanum(char c)
{
	return ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'));
}

char	*ft_strcapitalize(char *str)
{
	int	new_word;
	int	i;

	i = 0;
	new_word = 1;
	while (str[i] != '\0')
	{
		if (is_alphanum(str[i]))
		{
			if (new_word && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] -= 32;
			else if (!new_word && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] += 32;
			new_word = 0;
		}
		else
			new_word = 1;
		i++;
	}
	return (str);
}

int main(void) {
    char tests[][100] = {
        "",
        "   ;;; +++---===   ",
        "123 4567 89",
        "Hello World This Is Fine",
        "HELLO WORLD! THIS IS SHOUTING!",
        "hElLo wORld! mY nAme iS",
        "42isTheAnswer",
        "abc-def+ghi=jkl",
        "123abcDEF456ghi",
        "hello\nworld\tagain"
    };

    for (int i = 0; i < 10; i++) {
        printf("Test %d\n", i + 1);
        printf("Before: %s\n", tests[i]);
        ft_strcapitalize(tests[i]);
        printf("After : %s\n\n", tests[i]);
    }

    return 0;
}
