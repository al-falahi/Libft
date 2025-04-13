#include "libft.h"
#include <stdio.h>

int main(void)
{
    // Testing ft_strlen
    char str[] = "Hello, world!";
    int len = ft_strlen(str);
    printf("Length of '%s' is: %d\n", str, len);

    // Testing ft_memset
    char str_memset[20] = "Hello";
    ft_memset(str_memset, 'X', 3);  // Set first 3 chars to 'X'
    printf("Result after ft_memset: %s\n", str_memset);

    // Testing ft_bzero
    char str_bzero[20] = "Hello";
    ft_bzero(str_bzero, 3);  // Set first 3 chars to '\0'
    printf("Result after ft_bzero: %s\n", str_bzero);  // Should print "lo" because first 3 characters are zeroed

    return 0;
}

