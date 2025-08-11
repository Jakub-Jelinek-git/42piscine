/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjelinek <jjelinek@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:22:39 by jjelinek          #+#    #+#             */
/*   Updated: 2025/08/10 10:22:41 by jjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	count;

	count = 0;
	while (src[count] != '\0' && count < n)
	{
		dest[count] = src[count];
		count++;
	}
	while (count < n)
	{
		dest[count] = '\0';
		count++;
	}
	return (dest);
}

// Helper function to print bytes including nulls
void print_buffer(char *label, char *buf, unsigned int n) {
    printf("%s: \"", label);
    for (unsigned int i = 0; i < n; i++) {
        if (buf[i] == '\0')
            printf("\\0");
        else
            putchar(buf[i]);
    }
    printf("\"\n");
}

int main(void)
{

	char dest [] = "Ahoj";
	char source [] = "ahojvole";
	int n = 20;
	ft_strncpy(dest, source, n);
	printf("%s", dest);
    char src1[] = "Hello, world!";
    char src2[] = "Shortpppppppppppp";
    char src3[] = "";

    char dest1[20];
    char dest2[20];
    char dest3[20];
    char ref1[20];
    char ref2[20];
    char ref3[20];

    // Fill destination buffers with 'X' to see null-padding
    memset(dest1, 'X', sizeof(dest1));
    memset(dest2, 'X', sizeof(dest2));
    memset(dest3, 'X', sizeof(dest3));
    memset(ref1, 'X', sizeof(ref1));
    memset(ref2, 'X', sizeof(ref2));
    memset(ref3, 'X', sizeof(ref3));

    printf("Test 1 - Exact Length Copy (13 chars):\n");
    ft_strncpy(dest1, src1, 13);
    strncpy(ref1, src1, 13);
    print_buffer("Expected", ref1, 20);
    print_buffer("Result  ", dest1, 20);
    printf("\n");

    printf("Test 2 - Copy With Padding (n = 10):\n");
    ft_strncpy(dest2, src2, 10);
    strncpy(ref2, src2, 10);
    print_buffer("Expected", ref2, 20);
    print_buffer("Result  ", dest2, 20);
    printf("\n");

    printf("Test 3 - n = 0:\n");
    ft_strncpy(dest3, src1, 0);
    strncpy(ref3, src1, 0);
    print_buffer("Expected", ref3, 20);
    print_buffer("Result  ", dest3, 20);
    printf("\n");

    printf("Test 4 - Copy Empty String (n = 5):\n");
    ft_strncpy(dest3, src3, 5);
    strncpy(ref3, src3, 5);
    print_buffer("Expected", ref3, 20);
    print_buffer("Result  ", dest3, 20);
    printf("\n");

    return 0;
}
