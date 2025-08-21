/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:24:20 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/21 18:27:28 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	get_n_strings(char *str, char *charset)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		while (str[i] && is_separator(str[i], charset))
			i++;
		if (str[i] && !is_separator(str[i], charset))
		{
			num++;
			while (str[i] && !is_separator(str[i], charset))
				i++;
		}
	}
	return (num);
}

int	get_str_len(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !is_separator(str[i], charset))
		i++;
	return (i);
}

char	*get_string(char *str, char *charset)
{
	char	*string;
	int		n;

	n = 0;
	string = (char *)malloc(get_str_len(str, charset) + 1);
	if (!string)
		return (NULL);
	n = 0;
	while (*str && !is_separator(*str, charset))
	{
		string[n] = *str;
		n++;
		str++;
	}
	string[n] = '\0';
	return (string);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		j;
	int		len;

	j = 0;
	len = get_n_strings(str, charset);
	split = (char **)malloc((len + 1) * sizeof(char *));
	while (*str)
	{
		while (*str && is_separator(*str, charset))
			str++;
		if (*str)
		{
			split[j] = get_string(str, charset);
			str += get_str_len(str, charset);
			j++;
		}
	}
	split[j] = NULL;
	return (split);
}
