/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:06:50 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/27 13:02:40 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	put_str(int fd, char *str)
{
	while (*str)
		write(fd, str++, 1);
}

void	error(char *filename)
{
	put_str(2, "cat: ");
	put_str(2, basename(filename));
	put_str(2, ": ");
	put_str(2, strerror(errno));
	put_str(2, "\n");
}

void	display(int fd)
{
	int		n_read;
	char	buf[BUF_SIZE];

	n_read = read(fd, buf, BUF_SIZE);
	while (n_read > 0)
	{
		write(1, buf, n_read);
		n_read = read(fd, buf, BUF_SIZE);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		fd;

	i = 1;
	if (argc == 1)
		display(0);
	else
	{
		while (argv[i++])
		{
			fd = open(argv[i - 1], O_RDONLY);
			if (fd < 0)
				error(argv[i - 1]);
			else
			{
				display(fd);
				close(fd);
			}
		}
	}
	return (0);
}
