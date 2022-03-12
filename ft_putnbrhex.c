/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloyer-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:00:19 by gloyer-p          #+#    #+#             */
/*   Updated: 2021/11/25 14:44:20 by gloyer-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putnbrhex(unsigned int nbr, char *base, int count_print)
{
	unsigned int	size;

	size = ft_strlen(base);
	if (size < 2)
		return (-1);
	if (nbr >= size)
		count_print = ft_putnbrhex(nbr / size, base, count_print);
	write(1, &base[nbr % size], 1);
	return (count_print + 1);
}	
/*
#include <stdio.h>
#include <limits.h>
int main()
{
	int *p;
	int a;

	a = 2;
	p = &a;
	printf("------------printing a pointer-----------\n");
	write(1, "ft_putnbrhex: ", ft_strlen("ft_putnbrhex: ")); 
	//Attention 0x a rajoute
	printf("   output: %d",
		ft_putnbrhex((long long int) p, "0123456789abcdef", 0));
	printf("\nprintf using %%p: %p\n", p);
	printf("\n\n\n-----test with big and negative numbers----\n");
	write(1, "my fct: ", 8);
	ft_putnbrhex(-10, "0123456789abcdef", 0);
	printf("\nog fct: %x\n", -10);
	write(1, "my fct: ", 8);
	ft_putnbrhex(LONG_MAX, "0123456789abcdef", 0);
	printf("\nog fct: %x\n", LONG_MAX);
}
*/
