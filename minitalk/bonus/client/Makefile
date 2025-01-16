CC = cc 

CFLAGS = -Wall -Wextra -Werror

SRC = client_bonus.c
HEADERS = client_bonus.h libft.h

LIBFT = libft.a

OBJ_FILES = $(SRC:.c=.o)

NAME = client_bonus.out

all: $(NAME)

$(NAME):
		$(CC) $(CFLAGS) $(SRC) $(HEADER) $(LIBFT) -o $(NAME)

clean: 
		rm -f $(OBJ_FILES)

fclean:clean
		rm -f $(NAME)

re: fclean all

.PHONY :all clean fclean re