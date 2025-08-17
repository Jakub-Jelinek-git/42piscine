#include <unistd.h>

int main(int argc, char **argv)
{
	int	i;
	int n;

	n = argc - 1;
	while (n > 0)
	{
		i = 0;
		while (argv[n][i])
		{
			write(1, &argv[n][i], 1);
			i++;
		}
		write(1, "\n", 1);
		n--;
	}
	return (0);
}