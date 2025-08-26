/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:57:00 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/26 15:57:01 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	put_str(int fd, char *str)
{
	while (*str)
		write(fd, str++, 1);
}

void	*error(char *filename)
{
	put_str(2, "tail: cannot open '");
	put_str(2, basename(filename));
	put_str(2, "' for reading: ");
	put_str(2, strerror(errno));
	put_str(2, "\n");
	return (NULL);
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

int	get_byte_size(char *size_s)
{
	int	size;

	size = 0;
	while (*size_s)
	{
		size = size * 10 + (*size_s - '0');
		size_s++;
	}
	return (size);
}

void	header(char *filename)
{
	put_str(1, "==> ");
	put_str(1, basename(filename));
	put_str(1, " <==\n");
}
