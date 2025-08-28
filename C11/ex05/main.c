/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:04:05 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/28 13:10:49 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	print(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	calc(char **argv)
{
	int	(*ops[5])(int, int);

	ops[0] = add;
	ops[1] = sub;
	ops[2] = mul;
	ops[3] = divide;
	ops[4] = mod;
	if (argv[2][0] == '+')
		ft_putnbr(ops[0](ft_atoi(argv[1]), ft_atoi(argv[3])));
	else if (argv[2][0] == '-')
		ft_putnbr(ops[1](ft_atoi(argv[1]), ft_atoi(argv[3])));
	else if (argv[2][0] == '*')
		ft_putnbr(ops[2](ft_atoi(argv[1]), ft_atoi(argv[3])));
	else if (argv[2][0] == '/' && ft_atoi(argv[3]) == 0)
		print("Stop : division by zero");
	else if (argv[2][0] == '/')
		ft_putnbr(ops[3](ft_atoi(argv[1]), ft_atoi(argv[3])));
	else if (argv[2][0] == '%' && ft_atoi(argv[3]) == 0)
		print("Stop : modulo by zero");
	else if (argv[2][0] == '%')
		ft_putnbr(ops[4](ft_atoi(argv[1]), ft_atoi(argv[3])));
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	if (!(argv[2][0] == '/' || argv[2][0] == '+' || argv[2][0] == '-'
		|| argv[2][0] == '*' || argv[2][0] == '%') || argv[2][1] != '\0')
		write(1, "0\n", 2);
	else
		calc(argv);
	return (0);
}
