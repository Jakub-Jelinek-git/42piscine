CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs
INC_DIR = includes

SRC_FILES = ft_putchar.c \
			ft_swap.c \
			ft_putstr.c \
			ft_strlen.c \
			ft_strcmp.c
			

OBJECT_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(SRC_DIR)/, $(OBJECT_FILES))
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
