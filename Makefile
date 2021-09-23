NAME = header_generator
CL = clang
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I libft/ -I includes/
SANI = -fsanitize=address
LEAK = -fsanitize=leak
SRCS = auto_header.c get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L libft -lft

clean:
	make clean -C libft/
	rm -f $(OBJS)

fclean:
	make fclean -C libft/
	rm -f $(OBJS)
	rm -f $(NAME)

re: fclean all

sani:  $(OBJS)
	make -C libft/
	$(CC) $(CFLAGS) $(SANI) -o $(NAME) $(OBJS) -L libft -lft

leak: $(OBJS)
	make -C libft/
	$(CL) $(CFLAGS) $(LEAK) -o $(NAME) $(OBJS) -L libft -lft


.PHONY: clean fclean re
