#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (nb == 0)
		return (0);
	else
	{
		while (power--)
			result = result * nb;
	}
	return (result);
}

/*int main(int argc, char **argv)
{
	if (argc == 3)
		printf("%i\n", ft_iterative_power(atoi(argv[1]), atoi(argv[2])));
	return (0);
}*/
