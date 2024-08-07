CC		= cc
FLAGS	= -Wall -Wextra -Werror

SRCS	= main.c
OBJS	= $(SRCS:.c=.o)
NAME	= so_long

all: $(NAME)

$(NAME):
	$(CC) $(SRCS) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz  -o $(NAME)

%.o: %.c
	$(CC) /usr/include -Imlx -O3 -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all