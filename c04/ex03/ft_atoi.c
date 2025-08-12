#include <stdio.h>

int ft_atoi(char *str)
{
	int	output;
	int	is_negative;

	output = 0;
	is_negative = 1;
	while (*str)
	{
		if (*str == '-')
			is_negative *= -1;
		else if (*str >= '0' && *str <= '9')
		{
			while (*str >= '0' && *str <= '9')
			{
				output *= 10;
				output += (int)(*str - '0');
				str++;
			}
			return (output * is_negative);
		}
		str++;
	}
	return (output);
}

int main() {
    char *test_cases[] = {
        "   ---+--+1234ab567", // example from your guideline
        "42",
        "   +++---42abc",
        "   -+-+--1000xyz",
        "  +0",
        "   ---+++---",        // no digits, should return 0
        "123abc456",
        "   ",
        "",                   // empty string
        "  +--+--+00123",
    };

    int n_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < n_tests; i++) {
        printf("Input: \"%s\" => Output: %d\n", test_cases[i], ft_atoi(test_cases[i]));
    }

    return 0;
}
