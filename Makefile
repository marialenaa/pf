# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgallizz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/19 14:51:29 by mgallizz          #+#    #+#              #
#    Updated: 2021/03/19 14:51:33 by mgallizz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = clang

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

LIB_MAKE = make -C libft

SRC = 	setup/ft_init.c setup/parser.c getter/ft_get_flags.c getter/ft_get_arg.c treatment/ft_treat_u_i.c \
		transfo/ft_convert_putnbr_base.c transfo/ft_print.c ft_printf.c treatment/ft_utils.c \
		treatment/ft_treat_flag.c treatment/ft_treat_c_s.c treatment/ft_treat_x_p.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(LIB_MAKE)
		cp libft/libft.a $(NAME)
		ar rc $(NAME) $(OBJ)

clean: 
	$(RM) $(OBJ)
	$(LIB_MAKE) fclean

fclean: clean
		$(RM) $(NAME)
		$(LIB_MAKE) fclean
		
re: fclean all

.PHONY: all clean fclean re 
