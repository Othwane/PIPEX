NAME = pipex

SRCS = srcs/pipex.c srcs/utils.c srcs/argcheck.c srcs/cmdchecker.c srcs/openfds.c srcs/pipe_fork.c srcs/procmng.c srcs/split.c srcs/ft_printf.c

OBJS = ${SRCS:.c=.o}

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all claen fclean re
