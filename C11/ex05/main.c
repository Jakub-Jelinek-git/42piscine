/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:04:05 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/27 19:17:48 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "do_op.h"
int	main(int argc, char **argv)
{
	int (*ops[5])(int, int) = {add, sub, mul, divide, mod};
	if (argc != 4)
	return (0);
}
