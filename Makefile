# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gloyer-p <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/17 11:51:35 by gloyer-p          #+#    #+#              #
#    Updated: 2021/11/25 14:45:27 by gloyer-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_putchar_fd.c ft_putnbrhex.c ft_putstr_fd.c	ft_strlen.c ft_printf.c ft_putnbr_fd.c ft_putpointer.c ft_putunbr.c

OBJS	= ${SRCS:.c=.o}

CC		= gcc

RM 		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:	${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

INCLUDE = ft_printf.h

NAME	= libftprintf.a

all:	$(NAME)

$(NAME):	${OBJS} ${INCLUDE}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

clean:	
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re bonus
