# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/30 20:23:10 by coder             #+#    #+#              #
#    Updated: 2021/12/31 01:35:18 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRCS		=	so_long.c

OBJS		=	${SRCS:%.c=%.o}

CC 			=	gcc

LIB			=	-lbsd -lmlx -lXext -lX11 -lm -lz

LIBFT		=	./libs/libft/libft.a

# FLAGS 		=	-Wall -Werror -Wextra

.c.o:
			$(CC) $(FLAGS) -lmlx -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME): 	$(OBJS) $(LIBFT) $(MINILIBX)
			$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIB) $(LIBFT)

$(LIBFT):
			make bonus -C ./libs/libft

$(MINILIBX):
			cd ./libs/minilibx && ./configure && cd ../../
			
clean:
			rm -f $(OBJS)
			make clean -C ./libs/libft

fclean: 	clean
			rm -f $(NAME)
			make fclean -C ./libs/libft

re: 		fclean all

.PHONY: 	all clean fclean re bonus rebonus

# ---------------------------------------------------------------------------

# MINILIBX:=	.libs/minilibx/libmlx_Linux.a
