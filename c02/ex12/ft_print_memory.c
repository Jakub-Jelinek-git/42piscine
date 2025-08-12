/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:44:42 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/11 11:44:44 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_1_column(unsigned char *address)
{
	int				i;
	char			*hex_digits;
	unsigned long	addy_64;
	char			out;

	addy_64 = (unsigned long)address;
	hex_digits = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		out = hex_digits[(addy_64 >> ((15 - i) * 4)) & 0xF];
		write (1, &out, 1);
		i++;
	}
	write (1, ": ", 2);
}

void	print_2_column(unsigned char *address)
{
	char			*hex_digits;
	char			out[2];
	int				i;
	unsigned char	byte;

	i = 0;
	hex_digits = "0123456789abcdef";
	while (i < 16)
	{
		byte = *((unsigned char *)address + i);
		out[0] = hex_digits[byte >> 4];
		out[1] = hex_digits[byte & 0x0F];
		write(1, out, 2);
		if (i % 2 == 1)
			write (1, " ", 1);
		i++;
	}
}

void	print_2_column_last_l(unsigned char *address, int size_last_l)
{
	char			*hex_digits;
	char			out[2];
	int				i;
	unsigned char	byte;

	i = 0;
	hex_digits = "0123456789abcdef";
	while (i < size_last_l)
	{
		byte = *((unsigned char *)address + i);
		out[0] = hex_digits[byte >> 4];
		out[1] = hex_digits[byte & 0x0F];
		write(1, out, 2);
		if (i % 2 == 1)
			write (1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write (1, "  ", 2);
		if (i % 2 == 1)
			write (1, " ", 1);
		i++;
	}
}

void	print_3_column(unsigned char *address, int length)
{
	int				i;
	unsigned char	*c;

	i = 0;
	c = address;
	while (i < length)
	{
		if (*c >= ' ' && *c <= '~')
			write(1, c, 1);
		else
			write(1, ".", 1);
		c++;
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	currloop;
	unsigned char	*address;

	currloop = 0;
	address = (unsigned char *)addr;
	while (currloop < size / 16)
	{
		print_1_column(address);
		print_2_column(address);
		print_3_column(address, 16);
		address += 16;
		currloop++;
	}
	if (size % 16 > 0)
	{
		print_1_column(address);
		print_2_column_last_l(address, size % 16);
		print_3_column(address, size % 16);
	}
	return (addr);
}


int main(void)
{
    char test[] =
	"Bonjour les amin"
	"ches\t\n\tc\x07 est fo"
	"u\ttout\tce qu on"
	"peut faire avec\t"
	"\n\tprint_memory\n\n"
	"\n\tlol.lol.\n\0";


    ft_print_memory(test, sizeof(test) - 1);

    return 0;
}
