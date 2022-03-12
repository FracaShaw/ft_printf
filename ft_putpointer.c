/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloyer-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:27:49 by gloyer-p          #+#    #+#             */
/*   Updated: 2021/11/25 15:55:59 by gloyer-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloyer-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:05:11 by gloyer-p          #+#    #+#             */
/*   Updated: 2021/11/25 12:22:16 by gloyer-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putnbrbase_for_putpointer(unsigned long long int nbr,
		char *base, int count_print)
{
	unsigned int	size;

	size = ft_strlen(base);
	if (size < 2)
		return (-1);
	if (nbr >= size)
		count_print = ft_putnbrbase_for_putpointer(nbr / size,
				base, count_print);
	write(1, &base[nbr % size], 1);
	return (count_print + 1);
}	
/*
#include <stdio.h>

int main()
{
	int *p;
	int a;

	a = 2;
	p = &a;
	printf("------------printing a pointer-----------\n");
	write(1, "ft_putnbrbase: ", ft_strlen("ft_putnbrbase: ")); 
	//Attention 0x a rajoute
	printf("   output: %d",
		ft_putnbrbase((long long int) p, "0123456789abcdef", 0));
	printf("\nprintf using %%p: %p\n", p);
}
*/

int	ft_putpointer(void *p)
{
	ft_putstr_fd("0x", 1);
	return (ft_putnbrbase_for_putpointer((unsigned long long int) p,
			"0123456789abcdef", 0) + 2);
}
/*
#include <stdio.h>
#include <limits.h>
int main()
{
	void *p;
	int a;

	a = 2;
	p = &a;
	printf("------------printing a pointer-----------\n");
	write(1, "ft_putpointer: ", ft_strlen("ft_putpointer: "));
	printf("   output: %d", ft_putpointer(p));
	printf("\nprintf using %%p: %p\n", p);
	printf("\n\n\n------Test printf with NULL pointer------\n");
	p = NULL;
	printf("og: %p\n ", p);
	printf("   output: %d", ft_putpointer(p));
	printf("\n\n\n------Test ft_putpointer with limits.h--------\n");
	p = (void *) LONG_MIN;
	printf(" <--my fct");
	ft_putpointer(p);
	printf("\nog fct: %p\n", p);
	p = (void *) LONG_MAX;
	printf(" <--my fct");
	ft_putpointer(p);
	printf("\nog fct: %p\n", p);
	p = (void *) -ULONG_MAX;
	printf(" <--my fct");
	ft_putpointer(p);
	printf("\nog fct: %p\n", p);
	p = (void *) ULONG_MAX;
	printf(" <--my fct");
	ft_putpointer(p);
	printf("\nog fct: %p\n", p);
	p = (void *) -100;
	printf(" <--my fct");
	ft_putpointer(p);
	printf("\nog fct: %p\n", p);
}
*/
