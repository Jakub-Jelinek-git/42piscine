#include <stdio.h>
#include <string.h>
#include <unistd.h>

char *ft_strcat(char *dest, char *src)
{
	char	*origin_dest;

	origin_dest = dest;
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (origin_dest);
}

void reset_dest(char *dest, const char *src, size_t size) {
    memset(dest, 0, size);
    strcpy(dest, src);
}

void run_test(const char *init_dest, const char *src, size_t dest_size) {
    char dest1[dest_size];
    char dest2[dest_size];

    reset_dest(dest1, init_dest, dest_size);
    reset_dest(dest2, init_dest, dest_size);

    strcat(dest1, (char *)src);
    char *ft_res = ft_strcat(dest2, (char *)src);

    printf("Initial dest: \"%s\"\nSrc: \"%s\"\n", init_dest, src);
    printf("strcat result: \"%s\"\n", dest1);
    printf("ft_strcat result: \"%s\"\n", dest2);

    if (strcmp(dest1, dest2) == 0 && ft_res == dest2)
        printf("✅ PASS\n\n");
    else
        printf("❌ FAIL\n\n");
}

int main(void) {
    printf("Testing ft_strcat...\n\n");

    run_test("Hello, ", "World!", 100);
    run_test("", "Empty dest", 100);
    run_test("No src", "", 100);
    run_test("123", "456", 100);
    run_test("Concat ", " with multiple calls", 100);

    return 0;
}
