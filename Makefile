# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamzil <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 19:05:06 by aamzil            #+#    #+#              #
#    Updated: 2019/11/23 00:52:20 by aamzil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRC=	libft_src/*.c				\
		ft_printf.c					\
		my_putchar.c				\
		count_for_nb.c				\
		print_format.c				\
		print_space_zero.c			\
		trait_decimal.c				\
		trait_format.c				\
		trait_uint.c				\
		trait_lower_hexa.c			\
		trait_upper_hexa.c			\
		trait_char.c				\
		trait_pointer.c				\
		trait_string.c				\
		trait_percent.c				\
		get_precision_and_width.c	\

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar -rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
