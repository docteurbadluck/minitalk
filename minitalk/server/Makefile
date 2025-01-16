CC = cc 

CFLAGS = -Wall -Wextra -Werror 

SRC = server.c
HEADERS = server.h libft.h

LIBFT = libft.a

OBJ_FILES = $(SRC:.c=.o)

NAME = server.out

all: $(NAME)

$(NAME):
		$(CC) $(CFLAGS) $(SRC) $(HEADER) $(LIBFT) -o $(NAME)

clean: 
		rm -f $(OBJ_FILES)

fclean:clean
		rm -f $(NAME)

re: fclean all

.PHONY :all clean fclean re