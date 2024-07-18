# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/14 11:51:01 by pafranco          #+#    #+#              #
#    Updated: 2024/07/17 20:21:58 by pafranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_uitoa.c \
		  ft_flags_util.c \
		  ft_print_assign.c \
		  ft_print_misc.c \
		  ft_print_hexs.c \
		  ft_printf.c \

LSRCS	= libft/ft_atoi.c \
			libft/ft_bzero.c \
			libft/ft_calloc.c \
			libft/ft_isalnum.c \
			libft/ft_isalpha.c \
			libft/ft_isascii.c \
			libft/ft_isdigit.c \
			libft/ft_isprint.c \
			libft/ft_itoa.c \
			libft/ft_memchr.c \
			libft/ft_memcmp.c \
			libft/ft_memcpy.c \
			libft/ft_memmove.c \
			libft/ft_memset.c \
			libft/ft_putchar_fd.c \
			libft/ft_putendl_fd.c \
			libft/ft_putnbr_fd.c \
			libft/ft_putstr_fd.c \
			libft/ft_split.c \
			libft/ft_strchr.c \
			libft/ft_strdup.c \
			libft/ft_striteri.c \
			libft/ft_strjoin.c \
			libft/ft_strlcat.c \
			libft/ft_strlcpy.c \
			libft/ft_strlen.c \
			libft/ft_strmapi.c \
			libft/ft_strncmp.c \
			libft/ft_strnstr.c \
			libft/ft_strrchr.c \
			libft/ft_strtrim.c \
			libft/ft_substr.c \
			libft/ft_tolower.c \
			libft/ft_toupper.c \


HEAD	= ft_printf.h

OBJS	= ${SRCS:.c=.o}

LOBJS	= ${LSRCS:.c=.o}

DEPS	= ${SRCS:.c=.d}

LDEPS	= ${LSRCS:.c=.d}

NAME	= libftprintf.a

NAMEBONUSe	= libftprintf.a

AR		= ar rcs

RM		= rm -f

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -g


all: 		libft ${NAME}

libft:
				make -C libft

fclibft:
				make -C libft fclean

clibft:
				make -C libft clean

%.o:%.c Makefile libft/libft.a
				${CC} ${CFLAGS} -c $< -MMD

-include ${DEPS}
${NAME}:	${OBJS} ${HEAD}
				${AR} ${NAME} ${OBJS} ${LOBJS}

clean:		clibft
				${RM} ${OBJS} ${DEPS}

fclean:		clean fclibft
				${RM} ${NAME}

re:			fclean all


.PHONY:		clean fclean re all libft fclibfft clibft
