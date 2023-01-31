NAME = pipex

SRCS = $(wildcard srcs/*.c)

OBJS = $(patsubst %.c, %.o, $(SRCS))

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

claen:
	$(RM) $(OBJS)

fclean: claen
	$(RM) $(NAME)

re: fclean all

.PHONY: all claen fclean re