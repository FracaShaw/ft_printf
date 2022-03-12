/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloyer-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:00:24 by gloyer-p          #+#    #+#             */
/*   Updated: 2021/11/25 14:43:43 by gloyer-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

unsigned long int	ft_strlen(const char *s);
int					ft_putchar_fd(char c, int fd);
int					ft_putstr_fd(char *s, int fd);
int					ft_putnbr_fd(int n, int fd);
int					ft_putnbrhex(unsigned int nbr,
						char *base, int count_printe);
int					ft_putpointer(void *p);
int					ft_putunbr(unsigned int nbr, int count_print);
int					ft_printf(const char *c, ...);
#endif
