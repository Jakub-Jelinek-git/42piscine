/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:20:08 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/19 19:20:09 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (1);
		i++;
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
