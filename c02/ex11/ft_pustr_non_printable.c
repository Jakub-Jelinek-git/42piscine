/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pustr_non_printable.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:15:27 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/10 14:15:29 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char	*hex_digits;
	char	out[2];

	hex_digits = "0123456789abcdef";
	while (*str)
	{
		if (*str >= ' ' && *str <= '~')
			write(1, str, 1);
		else
		{
			write(1, "\\", 1);
			out[0] = hex_digits[(unsigned char)*str >> 4];
			out[1] = hex_digits[(unsigned char)*str & 0x0F];
			write(1, out, 2);
		}
		str++;
	}
}

int main(void)
{
    char test[] = "Hello\t\nHow are you?\t";
    ft_putstr_non_printable(test);
    return 0;
}