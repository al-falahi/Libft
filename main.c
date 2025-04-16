/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-fala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:01:01 by aal-fala          #+#    #+#             */
/*   Updated: 2025/04/14 21:01:01 by aal-fala         ###   ########.fr       */
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
}
