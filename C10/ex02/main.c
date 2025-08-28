/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:38:28 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/27 14:18:38 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char	*alloc_mem_for_file(char *filename)
{
	int		fd;
	char	buffer[BUF_SIZE];
	int		n_read;
	int		total_size;
	char	*str;

	total_size = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (error(filename));
	n_read = read(fd, buffer, BUF_SIZE);
	while (n_read > 0)
	{
		total_size += n_read;
		n_read = read(fd, buffer, BUF_SIZE);
	}
	close(fd);
	str = malloc(total_size + 1);
	if (!str)
		return (NULL);
	return (str);
}

char	*get_file_content(char	*filename)
{
	char	*file;
	int		fd;
	int		n_read;
	char	buffer[BUF_SIZE];
	int		i;

	i = 0;
	file = alloc_mem_for_file(filename);
	if (!file)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(file);
		return (NULL);
	}
	n_read = read(fd, buffer, 1);
	while (n_read > 0)
	{
		file[i++] = buffer[0];
		n_read = read(fd, buffer, 1);
	}
	file[i] = '\0';
	close(fd);
	return (file);
}
int	tail(char *filename, char *size_c)
{
	char	*file;
	int		bytes;
	int		size;
	int		start;

	size = 0;
	bytes = get_byte_size(size_c);
	file = get_file_content(filename);
	if (!file)
		return (1);
	while (file[size])
		size++;
	start = size - bytes;
	if (start < 0)
		start = 0;
	put_str(1, file + start);
	free(file);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;

	i = 3;
	if (argc == 3
		&& argv[1][0] == '-' && argv[1][1] == 'c')
		display(get_byte_size(argv[2]));
	else if (argc > 3 && argv[1][0] == '-' && argv[1][1] == 'c')
	{
		while (argv[i])
		{
			if (argc > 4)
				header(argv[i]);
			tail(argv[i], argv[2]);
			i++;
		}
	}
	return (0);
}
