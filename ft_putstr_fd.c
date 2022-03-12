/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloyer-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:12:03 by gloyer-p          #+#    #+#             */
/*   Updated: 2021/11/24 20:41:38 by gloyer-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}
/*
int	main()
{
	int fd;

	fd = open("hello.txt", O_RDWR);
	ft_putstr_fd("hello", fd);
	close (fd);
}
*/
