/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:08:00 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/13 19:08:02 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	is_invalid(char *base)
{
	int	i;
	int	n;

	i = 0;
	if (!base[0] || !base[1])
		return (1);
	while (base[i])
	{
		n = 1 + i;
		if (base[i] == '-' || base[i] == '+' || base[i] == ' '
			|| base[i] == '\t' || base[i] == '\n' || base[i] == '\v'
			|| base[i] == '\f' || base[i] == '\r')
			return (1);
		while (base[n])
		{
			if (base[i] == base[n])
				return (1);
			n++;
		}
		i++;
	}
	return (0);
}

int	ft_base_len(char *base)
{
	int	len;

	len = 0;
	while (base[len])
		len++;
	return (len);
}

int	is_in_base(char c, char *base)
{
	while (*base)
	{
		if (c == *base)
			return (1);
		base++;
	}
	return (0);
}

int	base_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	negative;
	int	result;
	int	base_len;

	negative = 1;
	result = 0;
	base_len = ft_base_len(base);
	if (is_invalid(base))
		return (0);
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative = -negative;
		str++;
	}
	while (is_in_base(*str, base))
	{
		result = result * base_len + base_index(*str, base);
		str++;
	}
	return (result * negative);
}

/*int main(void)
{
    printf("%d\n", ft_atoi_base("  ---+--+1011xyz", "01"));      
	// binary, should be -11
    printf("%d\n", ft_atoi_base("  +++123", "0123456789"));       
	// decimal, should be 123
    printf("%d\n", ft_atoi_base("ff", "0123456789abcdef"));       
	// hex, should be 255
    printf("%d\n", ft_atoi_base("zzz", "z"));                     
	// invalid base, should be 0
    printf("%d\n", ft_atoi_base("42", ""));                       
	// empty base, should be 0
    printf("%d\n", ft_atoi_base("7b", "0123456789abcdef"));       
	/ hex, should be 123
    return 0;
}*/
