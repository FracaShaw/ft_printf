/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloyer-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:09:03 by gloyer-p          #+#    #+#             */
/*   Updated: 2021/11/24 20:04:10 by gloyer-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "ft_printf.h"

unsigned long int	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (*(s + length))
		length++;
	return (length);
}
/*
int main()
{
	char *a = "hello";
	printf("ft:%lu og:%lu\n", ft_strlen(a), strlen(a));
	char *b = "hello\0hello";
	printf("ft:%lu og:%lu\n", ft_strlen(b), strlen(b));
	//char *c;
	//printf("ft:%lu og:%lu\n", ftstrlen(c), strlen(c));
	char *d = "";
	printf("ft:%lu og:%lu\n", ft_strlen(d), strlen(d));
	char *e = "    ";
	printf("ft:%lu og:%lu\n", ft_strlen(e), strlen(e));
	char f[5];
	printf("ft:%lu og:%lu\n", ft_strlen(f), strlen(f));
}
*/
