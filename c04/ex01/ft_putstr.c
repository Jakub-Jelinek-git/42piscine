#include <stdio.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;

	}
}

int main (void)
{
	char string[] = "i like monez";
	ft_putstr(string);
	return (0);
}
