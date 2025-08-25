/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:06:50 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/25 14:26:04 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define BUF_SIZE 30 * 1024

int	main(int argc, char** argv)
{
	int		n_read;
	char	buf[BUF_SIZE];
	int		i;
	int		fd;
	
	i = 1;
	if (argc == 1)
		while ((n_read = read(0, buf, BUF_SIZE)) > 0)
			write(1, buf, n_read);
	else
	{
		while (argv[i])
		{
			fd = open(argv[i], O_RDONLY);
			if (fd < 0)
				return ()
			i++;
		}
	}
	return (0);
}
