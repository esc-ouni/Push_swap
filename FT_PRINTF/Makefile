# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idouni <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 11:20:18 by idouni            #+#    #+#              #
#    Updated: 2022/11/21 11:20:21 by idouni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   = libftprintf.a

CC     = cc

RM     = rm -rf

FLAGS  = -Wall -Wextra -Werror

AR     = ar -rc

HR     = ft_printf.h

PR     = ft_printf.c \
		 ft_putchar_fd.c \
		 ft_puthex_fd.c \
		 ft_putstr_fd.c \
		 ft_putx_fd.c \
		 ft_putnbr_fd.c \
		 ft_putunsigned_fd.c \
		 ft_strlen.c

OBJ    = $(PR:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(HR)
	$(AR) $(NAME) $(OBJ)

%.o: %.c $(HR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 
