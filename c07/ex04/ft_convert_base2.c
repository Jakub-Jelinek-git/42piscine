/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:20:16 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/19 19:20:16 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_base_len(char *base);
int	ft_atoi_base(char *str, char *base);
int	is_invalid(char *base);

int	ft_get_len_nbr(int nbr, char *base)
{
	long	nbr_l;
	int		base_len;
	int		i;

	i = 0;
	base_len = ft_base_len(base);
	nbr_l = nbr;
	if (nbr_l <= 0)
	{
		i++;
		nbr_l = -nbr_l;
	}
	while (nbr_l > 0)
	{
		nbr_l = nbr_l / base_len;
		i++;
	}
	return (i);
}

static char	*handle_zero(char *base_to)
{
	char	*str;

	str = malloc(2);
	if (!str)
		return (NULL);
	str[0] = base_to[0];
	str[1] = '\0';
	return (str);
}

static void	fill_digits(char *output, long n, char *base_to, int pos)
{
	int	base_len;

	base_len = ft_base_len(base_to);
	while (n > 0)
	{
		output[pos--] = base_to[n % base_len];
		n /= base_len;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*output;
	int		num_in_10b;
	int		len;
	long	n;

	if (is_invalid(base_from) || is_invalid(base_to))
		return (NULL);
	num_in_10b = ft_atoi_base(nbr, base_from);
	if (num_in_10b == 0)
		return (handle_zero(base_to));
	len = ft_get_len_nbr(num_in_10b, base_to);
	output = malloc(len + 1);
	if (!output)
		return (NULL);
	output[len] = '\0';
	n = num_in_10b;
	if (n < 0)
	{
		output[0] = '-';
		n = -n;
	}
	fill_digits(output, n, base_to, len - 1);
	return (output);
}

/*int main()
{
	char *res;

	res = ft_convert_base("FF", "0123456789ABCDEF", "01");
	printf("%s\n", res); // -> "11111111"
	free(res);

	res = ft_convert_base("-42", "0123456789", "01234567");
	printf("%s\n", res); // -> "-52"
	free(res);
	return (0);
}*/
