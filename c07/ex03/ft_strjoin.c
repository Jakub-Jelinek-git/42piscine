#include <stdlib.h>

int	get_full_str_len(char **strs, int size, char *sep)
{
	int	i;
	int	n;
	int	strs_len;
	int	size_sep;

	i = 0;
	size = 0;
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

int get_str_len(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}

char *str_add(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i]
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*full_string;

	if (size == 0)
	{
		full_string = (char *)malloc(1);
		full_string[0] = '\0';
		return (full_string)
	}
	full_string = malloc(strs_len(strs, size) + 1 + ((size - 1) * s_l(sep)));
	if (!full_string)
		return (NULL);
	full_string = join
	return (full_string);
}

