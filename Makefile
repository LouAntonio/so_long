# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 17:16:28 by lantonio          #+#    #+#              #
#    Updated: 2024/08/08 17:40:57 by lantonio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
FLAGS	= -Wall -Wextra -Werror

MLXLIB	= mlx/libmlx.a
SRCS	= so_long.c\
			./srcs/ft_split.c\
			./srcs/map_validator.c

OBJS	= $(SRCS:.c=.o)
NAME	= so_long

all: $(NAME)

$(NAME): $(OBJS) $(MLXLIB)
	$(CC) $(OBJS) -Iincludes -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz  -o $(NAME)

$(MLXLIB):
	$(MAKE) -C ./mlx

%.o: %.c
	$(CC) /usr/include -Imlx -O3 -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C ./mlx

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./mlx

re: fclean all