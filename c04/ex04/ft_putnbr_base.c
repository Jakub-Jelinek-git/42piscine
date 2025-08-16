/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:59:45 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/13 12:59:47 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_invalid(char *base)
{
	int	i;
	int	n;

	i = 0;
	if (!base[0] || !base[1])
		return (1);
	else
	{
		while (base[i])
		{
			n = 1 + i;
			if (base[i] == '-' || base[i] == '+')
				return (1);
			while (base[n])
			{
				if (base[i] == base[n])
					return (1);
				n++;
			}
			i++;
		}
	}
	return (0);
}

int	ft_base_len(char *base)
{
	int	len;

	len = 0;
	while (*base)
	{
		len++;
		base++;
	}
	return (len);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nbr_l;
	int		base_len;

	base_len = ft_base_len(base);
	nbr_l = nbr;
	if (is_invalid(base))
		return ;
	if (nbr_l < 0)
	{
		ft_putchar('-');
		nbr_l = -nbr_l;
	}
	if (nbr_l < base_len)
		ft_putchar(base[nbr_l]);
	else
	{
		ft_putnbr_base((int)(nbr_l / base_len), base);
		ft_putnbr_base((int)(nbr_l % base_len), base);
	}
}

/*int main(void)
{
    ft_putnbr_base(-42, "0123456789");   // -42
    write(1, "\n", 1);
    ft_putnbr_base(-20, "0123456789ABCDEF"); // -FF
    write(1, "\n", 1);
    ft_putnbr_base(-10, "abytoc");          // -bab
    write(1, "\n", 1);
    ft_putnbr_base(0, "01");              // 0
    write(1, "\n", 1);
    ft_putnbr_base(-2147483648, "0123456789"); // -2147483648
    write(1, "\n", 1);
    ft_putnbr_base(-5, "0+1");            // Invalid base, prints nothing
    write(1, "\n", 1);
	ft_putnbr_base(-8, "poneyvif");    // Output: -op
    write(1, "\n", 1);
    ft_putnbr_base(-10, "poneyvif");   // Output: -on
    write(1, "\n", 1);
    ft_putnbr_base(-64, "poneyvif");   // Output: -opp
    write(1, "\n", 1);
	ft_putnbr_base(-83, "poneyvif");   // Output: -one
    write(1, "\n", 1);
    ft_putnbr_base(-255, "poneyvif");  // Output: -eff
    write(1, "\n", 1);
    return 0;
}*/
