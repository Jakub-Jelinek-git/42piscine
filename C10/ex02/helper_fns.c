/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:57:00 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/27 13:41:39 by jjelinek         ###   ########.fr       */
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

void	display(int bytes)
{
	int		n_read;
	char	*buf;
	char	temp[BUF_SIZE];
	int		i;

	buf  = malloc(bytes);
	if (!buf)
		return ;
	i = 0;
	n_read = read(0, temp, BUF_SIZE);
	while (n_read > 0)
	{
		while (i < n_read)
		{
			buf[i] = temp[i];
			
		}
		n_read = read(0, temp, BUF_SIZE);
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
