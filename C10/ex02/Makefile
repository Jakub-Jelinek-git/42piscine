CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
		helper_fns.c
INCL = head.h
OBJS = $(SRCS:.c=.o)

NAME = ft_tail

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCL) -o $(NAME) $(OBJS) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
