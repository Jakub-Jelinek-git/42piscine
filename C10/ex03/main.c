/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:57:01 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/26 18:41:55 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	fisrt_c(unsigned int offset)
{
	write()
}

void	display(fd)
{
	int		n_read;
	char	buf[BUF_SIZE];

	n_read = read(fd, buf, BUF_SIZE);
	while (0 < n_read)
	{
		
	}
	
}

int main(int argc, char **argv)
{
	if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'C')
		display(0);
	else if (argc > 2 && argv[1][0] == '-' && argv[1][1] == 'C')
	{
		
	}
	return (0);
}
