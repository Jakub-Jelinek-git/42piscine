/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:57:28 by jjelinek        #+#    #+#               */
/*   Updated: 2025/08/06 11:13:07 by jjelinek       ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// int main() {
// 	ft_putchar('c');
// 	return 0;
// }