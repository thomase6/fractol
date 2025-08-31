/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:24:53 by texenber          #+#    #+#             */
/*   Updated: 2025/08/29 09:15:23 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	find_format(va_list args, const char *format, size_t i, int count)
{
	if (format[i] == 's')
		count += count_putstr(va_arg(args, char *));
	else if (format[i] == 'c')
		count += count_putchar(va_arg(args, int));
	else if (format[i] == 'i' || format[i] == 'd')
		count += count_putnbr(va_arg(args, int));
	else if (format[i] == 'u')
		count += count_putuint(va_arg(args, unsigned int));
	else if (format[i] == 'x')
		count += putlowerhex(va_arg(args, unsigned int));
	else if (format[i] == 'X')
		count += putupperhex(va_arg(args, unsigned int));
	else if (format[i] == 'p')
		count += putaddress(va_arg(args, void *));
	else if (format[i] == '%')
		count += count_putchar('%');
	else
		return (-1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count = find_format(args, format, ++i, count);
			if (count == -1)
				return (va_end(args), -1);
			if (format[i - 1] == '%')
				i++;
		}
		else
			count += write (1, &format[i++], 1);
	}
	return (va_end(args), count);
}
/*
#include <limits.h>
#include <stdio.h>
int main(void)
{
//	int result = ft_printf("string to check how many %s\n", "characters");
	int	result;
	int result2;
//	char *str = "laura";

	result = ft_printf(NULL); 
	printf("\n%d\n", result);
	result2 = printf(NULL);
	printf("\n%d", result2);
}*/

// #include <stdio.h>
// #include <stddef.h>
// #include <limits.h>

// int	main(void)
// {
// 	// tests for strings
// 	printf("\n string tests:\n");
// 	//
// 	printf("\nlength is: %d\n", ft_printf("test %s, %s, another test %s, after", "string here", "str\0teere", NULL));
// 	printf("\nlength is: %d\n", printf("test %s, %s, another test %s, after", "string here", "str\0teere", (char *) NULL));

// 	// int tests
// 	printf("\n int tests:\n");
// 	//
// 	printf("\nlength is: %d\n", ft_printf("test %d, Max %d, Min %d, after", 123, 2147483647, -2147483648));
// 	printf("\nlength is: %d\n", printf("test %d, Max %d, Min %d, after", 123, (int) 2147483647, (int) -2147483648));
// 	printf("\nlength is: %d\n", ft_printf("test %d, Max %d, Min %d, after", 123, 2147483648, -2147483649));
// 	printf("\nlength is: %d\n", printf("test %d, Max %d, Min %d, after", 123, (int) 2147483648, (int) -2147483649));
// 	printf("\nlength is: %d\n", ft_printf("test %i, Max %i, Min %i, after", 123, 2147483647, -2147483648));
// 	printf("\nlength is: %d\n", printf("test %i, Max %i, Min %i, after", 123, (int) 2147483647, (int) -2147483648));
// 	printf("\nlength is: %d\n", ft_printf("test %i, Max %i, Min %i, after", 123, 2147483648, -2147483649));
// 	printf("\nlength is: %d\n", printf("test %i, Max %i, Min %i, after", 123, (int) 2147483648, (int) -2147483649));

// 	// unsigned int tests
// 	printf("\n unsigned int tests:\n");
// 	//
// 	printf("\nlength is: %d\n", ft_printf("test %u, Max %u, Min %u, after", 123, (unsigned int) 4294967295, 0 ));
// 	printf("\nlength is: %d\n", printf("test %u, Max %u, Min %u, after", 123, (unsigned int) 4294967295, 0));
// 	printf("\nlength is: %d\n", ft_printf("test %u, Max %u, Min %u, after", 123, (unsigned int) 4294967296, (unsigned int) -1 ));
// 	printf("\nlength is: %d\n", printf("test %u, Max %u, Min %u, after", 123, (unsigned int) 4294967296, (unsigned int) -1));

// 	// char tests
// 	printf("\n pointer tests:\n");
// 	//
// 	char	*test = "blabla";
// 	int		i = 0;
// 	printf("\nlength is: %d\n", ft_printf("test %p, str %p, str %p, after int", test, &test[2], &test[4]));
// 	printf("\nlength is: %d\n", printf("test %p, str %p, str %p, after int", test, &test[2], &test[4]));
// 	printf("\nlength is: %d\n", ft_printf("test %p, null %p, after int", NULL, &i));
// 	printf("\nlength is: %d\n", printf("test %p, null %p, after int", NULL, &i));

// 	// hex tests
// 	printf("\n hex tests:\n");
// 	//
// 	printf("\nlength is: %d\n", ft_printf("test %x, Max %x, Min %x, after", 123, (unsigned int) 4294967295, 0 ));
// 	printf("\nlength is: %d\n", printf("test %x, Max %x, Min %x, after", 123, (unsigned int) 4294967295, 0));
// 	printf("\nlength is: %d\n", ft_printf("test %x, Max %x, Min %x, after", 123, (unsigned int) 4294967296, (unsigned int) -1 ));
// 	printf("\nlength is: %d\n", printf("test %x, Max %x, Min %x, after", 123, (unsigned int) 4294967296, (unsigned int) -1));
// 	printf("\nlength is: %d\n", ft_printf("test %x, Max %x, Min %x, after", 873, (unsigned int) 42949, (unsigned int) 9999 ));
// 	printf("\nlength is: %d\n", printf("test %x, Max %x, Min %x, after", 873, (unsigned int) 42949, (unsigned int) 9999));
// 	ft_printf("\n");
// 	printf("\nlength is: %d\n", ft_printf("test %X, Max %X, Min %X, after", 123, (unsigned int) 4294967295, 0 ));
// 	printf("\nlength is: %d\n", printf("test %X, Max %X, Min %X, after", 123, (unsigned int) 4294967295, 0));
// 	printf("\nlength is: %d\n", ft_printf("test %X, Max %X, Min %X, after", 123, (unsigned int) 4294967296, (unsigned int) -1 ));
// 	printf("\nlength is: %d\n", printf("test %X, Max %X, Min %X, after", 123, (unsigned int) 4294967296, (unsigned int) -1));
// 	printf("\nlength is: %d\n", ft_printf("test %X, Max %X, Min %X, after", 873, (unsigned int) 42949, (unsigned int) 9999 ));
// 	printf("\nlength is: %d\n", printf("test %X, Max %X, Min %X, after", 873, (unsigned int) 42949, (unsigned int) 9999));

// 	// null check
// 	printf("\n NULL tests:\n");
// 	//
// 	printf("\nlength is: %d\n", ft_printf(NULL));
// 	printf("\nlength is: %d\n", printf(NULL));

// 	// character checks
// 	printf("\n character tests:\n");
// 	//
// 	printf("\nlength is: %d\n", ft_printf("test %c, %c, another test %c, after", '?', 2, 200));
// 	printf("\nlength is: %d\n", printf("test %c, %c, another test %c, after", '?', 2, 200));
// 	printf("\nlength is: %d\n", ft_printf("test %c, %c, another test %c, after", 'a', 'b', '1'));
// 	printf("\nlength is: %d\n", printf("test %c, %c, another test %c, after", 'a', 'b', '1'));

// 	// percentage checks
// 	printf("\n percentage%% tests:\n");
// 	//
// 	printf("\nlength is: %d\n", ft_printf("test %%, %%, another test %%, after"));
// 	printf("\nlength is: %d\n", printf("test %%, %%, another test %%, after"));

// 	// invalid format specifiers
// 	printf("\n invalid format specifiers\n");
// 	//
// 	printf("\nlength is: %d\n", ft_printf("test %, %%, another test %%, after", 12));
// 	printf("\nlength is: %d\n", printf("test %, %%, another test %%, after", 12));
// 	printf("\nlength is: %d\n", ft_printf("%%%%c"));
// 	printf("\nlength is: %d\n", printf("%%%%v")); // this works because format specifier is ' ' as space, WE DON'T NEED TO HANDLE THIS, IT IS BONUS!!!!!!!!
// }
