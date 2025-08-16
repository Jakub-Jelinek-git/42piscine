#include <stdio.h>
#include <stdlib.h>

int ft_find_next_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (0);
	while (i * i <= nb)
	{
		if (nb % i == 0)
		{
			nb++;
			i = 2;
		}
		else
			i++;
	}
	return (nb);

}

int main(int argc, char **argv)
{
	if (argc == 2)
		printf("%i\n", ft_find_next_prime(atoi(argv[1])));
	return (0);
}