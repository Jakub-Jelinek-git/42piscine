/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:47:04 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/25 10:47:05 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	current;

	current = 0;
	while (s1[current] || s2[current])
	{
		if (s1[current] != s2[current])
			return ((int)((unsigned char)s1[current])
			- (int)((unsigned char)s2[current]));
		current++;
	}
	return (0);
}
