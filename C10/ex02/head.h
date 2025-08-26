/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:38:54 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/26 18:14:23 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# define BUF_SIZE 30720
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>

void	*error(char *filename);
void	put_str(int fd, char *str);
void	display(int fd);
int		get_byte_size(char *size_s);
void	header(char *filename);

#endif
