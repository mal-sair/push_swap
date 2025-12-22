NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c \
      utils.c \
      parsing.c \
      operations_swap.c \
      operations_push.c \
      operations_rotate.c \
      operations_rev_rotate.c

OBJ = $(SRC:.c=.o)

BONUS_SRC = checker.c \
            utils.c \
            parsing.c \
            operations_swap.c \
            operations_push.c \
            operations_rotate.c \
            operations_rev_rotate.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
