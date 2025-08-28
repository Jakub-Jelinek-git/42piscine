/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:35:29 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/27 14:29:50 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#define BUF_SIZE 4096

void	put_str(int fd, char *str)
{
	while(*str)
		write(fd, str++, 1);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		n_read;
	char	buf[BUF_SIZE];
	
	if (argc == 1)
	{
		put_str(2, "File name missing.\n");
		return (1);
	}
	else if (argc != 2)
	{
		put_str(2, "Too many arguments.\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		put_str(2, "Cannot read file.\n");
		return (1);
	}
	while ((n_read = read(fd, buf, BUF_SIZE)) > 0)
		write(1, buf, n_read);
	close(fd);
	return (0);
}
