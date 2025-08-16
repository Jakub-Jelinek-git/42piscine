#include <stdio.h>
#include <stdlib.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (nb == 0)
		return (0);
	return (nb * ft_recursive_power(nb, power - 1));
}

int main(int argc, char **argv)
{
	if (argc == 3)
		printf("%i\n", ft_recursive_power(atoi(argv[1]), atoi(argv[2])));
	return (0);
}