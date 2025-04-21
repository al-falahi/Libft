/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-fala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:01:01 by aal-fala          #+#    #+#             */
/*   Updated: 2025/04/21 19:11:05 by aal-fala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	char	str[20] = "Hello, world!";
	int	len;
	char	str_memset[20] = "Hello";
	char	str_bzero[20] = "Hello";
	char	src[] = "Hello, world!";
	char	dst[20];

	len = ft_strlen(str);
	printf("Length of '%s' is: %d\n", str, len);
	ft_memset(str_memset, 'X', 3);
	printf("Result after ft_memset: %s\n", str_memset);
	ft_bzero(str_bzero, 3);
	printf("Result after ft_bzero: %s\n", str_bzero);
	ft_memcpy(dst, src, 13);
	printf("Destination after memcpy: %s\n", dst);
	printf("ft_isalpha('A') = %d\n", ft_isalpha('A')); // Should return 1
	printf("ft_isalpha('z') = %d\n", ft_isalpha('z')); // Should return 1
	printf("ft_isalpha('3') = %d\n", ft_isalpha('3')); // Should return 0
	printf("ft_isdigit('0') = %d\n", ft_isdigit('0')); // Should return 1
	printf("ft_isdigit('9') = %d\n", ft_isdigit('9')); // Should return 1
	printf("ft_isdigit('A') = %d\n", ft_isdigit('A')); // Should return 0
	printf("ft_isalnum('A') = %d\n",ft_isalnum('A'));  // returns 1
	printf("ft_isalnum('9') = %d\n",ft_isalnum('9')); // returns 1
	printf("ft_isalnum('$') = %d\n",ft_isalnum('$')); // returns 0
	printf("Is 'A' an ASCII character? %d\n", ft_isascii('A'));  // 1
	printf("Is 128 an ASCII character? %d\n", ft_isascii(128));  // 0
	printf("Is 'A' printable? %d\n", ft_isprint('A'));  // 1 (Yes, 'A' is printable)
	printf("Is 10 printable? %d\n", ft_isprint(10));   // 0 (No, 10 is newline and not printable)
	printf("Is ' ' (space) printable? %d\n", ft_isprint(' '));  // 1 (Yes, space is printable)
	printf("Is '~' printable? %d\n", ft_isprint('~'));  // 1 (Yes, tilde is printable)
	// ft_toupper
	char ch = 'b';
	printf("Orginal char: %c, Uppercase: %c\n", ch, ft_toupper(ch));
	// ft_tolower
	ch = 'B';
	printf("Orginal char: %c, Lowercase: %c\n", ch, ft_tolower(ch));
	// ft_strchr
	const	char	*strchr = "Hello, world";
	char			*result = ft_strchr(strchr, 'o');

	if (result)
		printf("Found 'o' at: %s\n", result);
	else
		printf("'o' not found.\n");
	// ft_strrchr
	const   char    *strrchr = "Hello, world";
	char            *resultr = ft_strrchr(strrchr, 'o');
	if (result)
         printf("Found 'o' at: %s\n", resultr);
	else
         printf("'o' not found.\n");
	//ft_strncmp
	printf("%d\n", ft_strncmp("abc", "abc", 3));    // 0
	printf("%d\n", ft_strncmp("abc", "abd", 3));    // -1 or -100 depending on encoding
	printf("%d\n", ft_strncmp("abc", "abcde", 5));  // negative
	//ft_strmemchr
	char	data[] = "abcdefg";
	char	*res = ft_memchr(data, 'd', 7);

	if (res)
		printf("Found: %s\n", res);
	else
		printf("Not found\n");
	//ft_memcmp
	char	a[] = "abcde";
	char	b[] = "abCde";
	int		resm = ft_memcmp(a, b, 5);
	if (resm == 0)
		printf("Blocks are equle\n");
	else
		printf("Blocks differ: %d\n", resm);
	//ft_strnstr
	const char	*big = "Hello, this is a test string.";
	const char	*small = "test";
	char		*found = ft_strnstr(big, small, 20);
	if (found)
		printf("Found: %s\n", found);
	else
		printf("Not found within limit.\n");
	//ft_atoi
	printf("%d\n", ft_atoi("   -42"));
	printf("%d\n", ft_atoi("4193 with words"));
	printf("%d\n", ft_atoi("+123"));
	printf("%d\n", ft_atoi("abc"));
	//part 2
	//ft_substr
	printf("ft_substr: %s\n", ft_substr("abcdef", 2, 3));
	//ft_strjoin
	char	*s1 = "Hello";
	char	*s2 = "World";
	char	*joined;
	joined = ft_strjoin(s1, s2);
	printf("Result: '%s'\n", joined);
	free(joined);
	//ft_strtrim
	char *trimmed;
	trimmed = ft_strtrim("  \t\n42 Antwerp\t\n  ", " \n\t");
	printf("Trimmed: '%s'\n", trimmed);
	free(trimmed);
	//ft_split
	char **resultt;
	int i = 0;
    resultt = ft_split("Hello 42 Network", ' ');

    if (!resultt)
    {
        printf("ft_split failed!\n");
        return (1);
    }

    while (resultt[i])
    {
        printf("Word %d: '%s'\n", i, resultt[i]);
        free(resultt[i]);
        i++;
    }
    free(resultt);}
