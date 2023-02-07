# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idouni <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 13:57:12 by idouni            #+#    #+#              #
#    Updated: 2023/01/24 14:03:43 by idouni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   = push_swap

NAME_B  = checker

CC     = cc

RM     = rm -rf

FLAGS  = -Wall -Wextra -Werror

HR     = push_swap.h

MND    = push_swap.c

BNS    = checker_bonus.c \
		tools_bonus.c \
		tools2_bonus.c \
		tools3_bonus.c \

TLS    = tools.c \
		lists.c \
		lists2.c \
		tools_1.c \
		tools_2.c \
		tools_3.c \
		tools_4.c \
		tools_5.c \
		tools_6.c \
		tools_7.c \
		G_N_L/get_next_line.c \
		G_N_L/get_next_line_utils.c \
		algo.c

FPF    = FT_PRINTF/libftprintf.a

LBFT   = LIBFT/libft.a

OBJ_M  = $(MND:%.c=%.o)

OBJ_T  = $(TLS:%.c=%.o)

OBJ_B  = $(BNS:%.c=%.o)

all: PRINTF LIBFT $(NAME)

PRINTF:
	@make -C FT_PRINTF

LIBFT:
	@make -C LIBFT

$(NAME): $(OBJ_M) $(OBJ_T) $(HR) 
	@$(CC) $(LBFT) $(FPF) $(OBJ_T) $(OBJ_M) -o $(NAME)
	@clear && echo "==$(NAME)_compiled==========="

$(NAME_B): $(OBJ_B) $(OBJ_T) $(HR)
	@$(CC) $(LBFT) $(FPF) $(OBJ_T) $(OBJ_B) -o $(NAME_B)
	@clear && echo "==$(NAME_B)_compiled==========="

%.o: %.c $(HR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@make clean -C FT_PRINTF
	@make clean -C LIBFT
	$(RM) $(OBJ_M)
	$(RM) $(OBJ_B)
	$(RM) $(OBJ_T)
	@clear && echo "==Object_files_deleted======="

fclean: clean
	@make fclean -C FT_PRINTF
	@make fclean -C LIBFT
	$(RM) $(NAME)
	$(RM) $(NAME_B)
	@clear && echo "==All_created_files_deleted=="

bonus: LIBFT PRINTF $(NAME_B)

re: fclean all
	@clear && echo "==Compilation_reseted========"

.PHONY: all bonus clean fclean re LIBFT PRINTF
