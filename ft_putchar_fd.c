/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloyer-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 19:02:55 by gloyer-p          #+#    #+#             */
/*   Updated: 2021/11/24 17:10:40 by gloyer-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
/*
int main()
{
	int fd;

	fd = open("hello.txt", O_RDWR);
	ft_putchar_fd('a', fd);
}
*/
