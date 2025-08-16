#include <stdio.h>
#include <stdlib.h>

int ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);

}

int main(int argc, char **argv)
{
	if (argc == 2)
		printf("%i\n", ft_sqrt(atoi(argv[1])));
	return (0);
}