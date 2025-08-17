#include <unistd.h>

void swap(char **a, char **b)
{
	char *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	should_swap(char *str1, char *str2)
{
	while (*str1 || *str2)
	{
		if (*str1 > *str2)
			return (1);
		else if (*str1 < *str2)
			return (0);
		str1++;
		str2++;
	}
	return (0);
}

void	ft_print_params(int argc, char **argv)
{
	int	i;
	int n;

	n = 1;
	while (n < argc)
	{
		i = 0;
		while (argv[n][i])
		{
			write(1, &argv[n][i], 1);
			i++;
		}
		write(1, "\n", 1);
		n++;
	}
}

int main(int argc, char **argv)
{
	int	i;
	int	sorted;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 1;
		while (i < argc - 1)
		{
			if (should_swap(argv[i], argv[i + 1]))
			{
				sorted = 0;
				swap(&argv[i], &argv[i + 1]);
			}
			i++;
		}
	}
	ft_print_params(argc, argv);
	return (0);
}
