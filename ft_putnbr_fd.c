/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloyer-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:15:50 by gloyer-p          #+#    #+#             */
/*   Updated: 2021/11/24 20:02:17 by gloyer-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	divgen1(int n)
{
	int	div;
	int	i;

	div = n;
	i = 0;
	while (div != 0)
	{
		div = div / 10;
		i++;
	}
	return (i);
}

int	divgen2(int i)
{
	int	div;

	div = 1;
	while (i > 1)
	{
		div *= 10;
		i--;
	}
	return (div);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	div;
	int	temp;
	int	count_print;

	count_print = 0;
	if (n == -2147483648)
	{
		return (ft_putstr_fd("-2147483648", fd));
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		count_print++;
		n = -n;
	}
	div = divgen2(divgen1(n));
	while (div != 0)
	{
		temp = n / div;
		n = n % div;
		ft_putchar_fd(temp + '0', fd);
		count_print++;
		div /= 10;
	}
	return (count_print);
}
/*
int main()
{
	int fd;

	fd = open("hello.txt", O_RDWR);
	ft_putnbr_fd(-42, fd);
	close(fd);
}
*/
