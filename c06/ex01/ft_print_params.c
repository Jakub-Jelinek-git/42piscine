int main(int argc, char **argv)
{
	int	i;
	int n;

	i = 0;
	n = 0;
	while (n < argc)
	{
		while (argv[n][i])
		{
			write(1, &argv[n][i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}