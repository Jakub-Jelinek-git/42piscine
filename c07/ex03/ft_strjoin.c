/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:28:18 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/19 14:28:19 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	get_full_str_len(char **strs, int size, char *sep)
{
	int	i;
	int	n;
	int	strs_len;
	int	size_sep;

	i = 0;
	strs_len = 0;
	size_sep = 0;
	while (i < size)
	{
		n = 0;
		while (strs[i][n])
		{
			strs_len++;
			n++;
		}
		i++;
	}
	while (sep[size_sep])
		size_sep++;
	return (strs_len + 1 + ((size - 1) * size_sep));
}

int	get_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*str_add(char *dest, char *src)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (dest[i])
		i++;
	while (src[n])
	{
		dest[i + n] = src[n];
		n++;
	}
	dest[i + n] = '\0';
	return (dest);
}

char	*fill(char *string, int size, char **strs, char *sep)
{
	int	n;

	n = 0;
	while (n < size - 1)
	{
		string = str_add(string, strs[n]);
		string = str_add(string, sep);
		n++;
	}
	string = str_add(string, strs[n]);
	return (string);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*full_string;

	if (size == 0)
	{
		full_string = (char *)malloc(1);
		full_string[0] = '\0';
		return (full_string);
	}
	full_string = (char *)malloc(get_full_str_len(strs, size, sep));
	if (!full_string)
		return (NULL);
	full_string[0] = '\0';
	full_string = fill(full_string, size, strs, sep);
	return (full_string);
}

/*int main(void)
{
    char *arr1[] = {"Hello", "world", "42", "Piscine"};
    char *arr2[] = {"OnlyOne"};
    char *sep = " - ";
    char *res;

    // Test 1: normal case with several strings
    res = ft_strjoin(4, arr1, sep);
    if (res)
    {
        printf("Test 1: %s\n", res); // Expected: Hello - world - 42 - Piscine
        free(res);
    }

    // Test 2: single string
    res = ft_strjoin(1, arr2, sep);
    if (res)
    {
        printf("Test 2: %s\n", res); // Expected: OnlyOne
        free(res);
    }

    // Test 3: empty array
    res = ft_strjoin(0, arr1, sep);
    if (res)
    {
        printf("Test 3: '%s'\n", res); // Expected: '' (empty string)
        free(res);
    }

    // Test 4: separator is empty string
    char *sep2 = "";
    res = ft_strjoin(4, arr1, sep2);
    if (res)
    {
        printf("Test 4: %s\n", res); // Expected: Helloworld42Piscine
        free(res);
    }

    return 0;
}*/
