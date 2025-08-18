/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:26:17 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/18 16:26:18 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*new_string;

	i = 0;
	while (src[i])
		i++;
	new_string = (char *)malloc(i + 1);
	if (!new_string)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new_string[i] = src[i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

/*int main(void)
{
	char src[] = "string";
	printf("%p\n", src);
	printf("%s\n", src);
	char *new_string = ft_strdup(src);
	printf("%p\n", new_string);
	printf("%s\n", new_string);
	free(new_string);
	return (0);
}*/
