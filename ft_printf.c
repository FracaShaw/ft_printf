/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloyer-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:14:05 by gloyer-p          #+#    #+#             */
/*   Updated: 2021/11/25 14:56:08 by gloyer-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	print_not_percentage(const char *c, int i)
{
	while (c[i] != '%' && c[i])
	{
		ft_putchar_fd(c[i], 1);
		i++;
	}
	if (c[i] == '%')
		return (i + 1);
	return (i);
}

int	the_cases(const char *c, int i, va_list list)
{
	void	*p;

	if (c[i] == 'c')
		return (ft_putchar_fd(va_arg(list, int), 1));
	else if (c[i] == 's')
	{
		p = va_arg(list, char *);
		if (p == NULL)
			return (ft_putstr_fd("(null)", 1));
		return (ft_putstr_fd(p, 1));
	}
	else if (c[i] == 'p')
		return (ft_putpointer(va_arg(list, void *)));
	else if (c[i] == 'd' || c[i] == 'i')
		return (ft_putnbr_fd(va_arg(list, int), 1));
	else if (c[i] == 'u')
		return (ft_putunbr(va_arg(list, unsigned int), 0));
	else if (c[i] == 'x')
		return (ft_putnbrhex(va_arg(list, int), "0123456789abcdef", 0));
	else if (c[i] == 'X')
		return (ft_putnbrhex(va_arg(list, int), "0123456789ABCDEF", 0));
	else if (c[i] == '%')
		return (ft_putchar_fd('%', 1));
	else
		return (-1);
}

int	ft_printf(const char *c, ...)
{
	int		i;
	va_list	list;
	int		check;
	int		count;

	va_start(list, c);
	count = 0;
	i = 0;
	while (c[i])
	{
		i = print_not_percentage(c, i);
		if (c[i - 1] == '%')
		{
			check = the_cases(c, i, list);
			if (check < 0)
				return (-1);
			count += check - 2;
			i++;
		}
	}
	va_end(list);
	return (i + count);
}
/*
#include <stdio.h>
int main()
{
	int *p;
	int a;

	a = 2;
	p = &a;

	ft_printf("-----test with a simple char------\n");
	ft_printf("   output: %d\n", ft_printf("my fct: 01234%c6789", '5'));
	printf("   output: %d\n", printf("og fct: 01234%c6789", '5'));
	ft_printf("\n-----test with a simple string-----\n");
	ft_printf("   output: %d\n", ft_printf("my fct: 01234%s89", "567"));
	printf("   output: %d\n", printf("og fct: 01234%s89", "567"));
	ft_printf("\n----test with a simple pointer----\n");
	ft_printf("   output: %d\n", ft_printf("my fct: %p", p));
	printf("   output: %d\n", printf("og fct: %p", p));
	ft_printf("\n------test with a simple int------\n");
	ft_printf("   output: %d\n", ft_printf("my fct: %d123456789", 0));
	printf("   output: %d\n", printf("og fct: %d123456789", 0));
	ft_printf("\n------test with a simple unsigned int-------\n");
	ft_printf("   output: %d\n", ft_printf("my fct: 0%u", 123456789));
	printf("   output: %d\n", printf("og fct: 0%u", 123456789));
	ft_printf("\n--------test with a simple hexa number------\n");
	ft_printf("   output: %d\n", ft_printf("my fct: 0%x", 886718345));
	printf("   output: %d\n", printf("og fct: 0%x", 886718345)); 
	ft_printf("\n--------test with %%%% ------------\n");
	ft_printf("   output: %d\n", ft_printf("my fct: %%"));
	printf("   output: %d\n", printf("og fct: %%"));
	ft_printf("\n---------test with char and int--------\n");
	ft_printf("   output: %d\n", ft_printf("my fct: %c01234%d6789%c", '[', 5, ']'));
	printf("   output: %d\n", printf("og fct: %c01234%d6789%c", '[', 5, ']'));
	ft_printf("\n\n\n------some tests on printf------\n");
	ft_printf("   output: %d\n", ft_printf("my fct: %s", NULL));
	printf("   output: %d\n", printf("og fct: %s", NULL));
}
*/
