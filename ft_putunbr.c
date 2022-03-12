/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloyer-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:02:07 by gloyer-p          #+#    #+#             */
/*   Updated: 2021/11/24 20:03:45 by gloyer-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nbr, int count_print)
{
	if (nbr >= 10)
		count_print = ft_putunbr(nbr / 10, count_print);
	ft_putnbr_fd(nbr % 10, 1);
	return (count_print + 1);
}
/*
#include <stdio.h>

int main()
{
	unsigned int u;

	u = 4294967295;
	printf("   output: %d", ft_putunbr(u, 0));
}
*/
