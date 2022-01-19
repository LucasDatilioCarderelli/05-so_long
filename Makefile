# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 14:21:14 by ldatilio          #+#    #+#              #
#    Updated: 2022/01/18 23:18:27 by ldatilio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	so_long
NAME_BONUS		:=	so_long_bonus

CC				:=	gcc

CFLAGS			:=	-Wall -Werror -Wextra
LIB				:=	-lbsd -lmlx -lXext -lX11 -lm -lz

LIBFT			:=	./libft/libft.a

DIR				:=	./src/
DIR_BONUS		:=	./src_bonus/

SRC		:=		$(addprefix $(DIR),	\
				so_long.c			\
				read_map.c			\
				render_game.c		\
				exit_free.c			\
				verify_error.c		\
				player_move.c		\
				)
SRC_BONUS =		$(addprefix $(DIR_BONUS),\
				so_long.c				\
				read_map.c				\
				render_game.c			\
				exit_free.c				\
				verify_error.c			\
				player_move.c			\
				enemy_move.c			\
				)

OBJS			:=	${SRC:%.c=%.o}
OBJS_BONUS		:=	${SRC_BONUS:.c=.o}

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)
bonus: 			$(NAME_BONUS)

$(NAME): 		$(LIBFT) $(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB) $(LIBFT)

$(NAME_BONUS):	$(LIBFT) $(OBJS_BONUS)
				$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIB) $(LIBFT)

$(LIBFT):
				make bonus -C ./libft

clean:
				rm -f $(OBJS) $(OBJS_BONUS)
				make clean -C ./libft

fclean:			clean
				rm -f $(NAME) $(NAME_BONUS)
				make fclean -C ./libft

re:				fclean all

rebonus:		fclean bonus

.PHONY: 		all, clean, fclean, re, bonus, rebonus