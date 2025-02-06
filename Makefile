CC = cc 
CFLAGS = -Wall -Wextra -Werror 
LIBFT = libft/libft.a

NAME = server
SRC_SERVER = server.c
HEADERS_SERVER = server.h libft/libft.h
OBJ_FILES_SERVER = $(SRC_SERVER:.c=.o)

NAME2 = client
SRC_CLIENT = client.c
HEADERS_CLIENT = client.h libft/libft.h
OBJ_FILES_CLIENT = $(SRC_CLIENT:.c=.o)


NAME_BONUS = server_bonus
SRC_SERVER_BONUS = server_bonus.c
HEADERS_SERVER_BONUS = server_bonus.h libft/libft.h
OBJ_FILES_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)

NAME2_BONUS = client_bonus
SRC_CLIENT_BONUS = client_bonus.c
HEADERS_CLIENT_BONUS = client_bonus.h libft/libft.h
OBJ_FILES_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)

all: make_libft $(NAME) $(NAME2)

$(NAME): $(OBJ_FILES_SERVER)
		$(CC) $(CFLAGS) $(OBJ_FILES_SERVER) $(LIBFT) -o $(NAME)

$(NAME2): $(OBJ_FILES_CLIENT)
		$(CC) $(CFLAGS) $(OBJ_FILES_CLIENT) $(LIBFT) -o $(NAME2)

$(OBJ_FILES_SERVER): %.o: %.c $(HEADERS_SERVER)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_FILES_CLIENT): %.o: %.c $(HEADERS_CLIENT)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: make_libft $(NAME_BONUS) $(NAME2_BONUS)

$(NAME_BONUS): $(OBJ_FILES_SERVER_BONUS)
		$(CC) $(CFLAGS) $(OBJ_FILES_SERVER_BONUS) $(LIBFT) -o $(NAME_BONUS)

$(NAME2_BONUS): $(OBJ_FILES_CLIENT_BONUS)
		$(CC) $(CFLAGS) $(OBJ_FILES_CLIENT_BONUS) $(LIBFT) -o $(NAME2_BONUS)

$(OBJ_FILES_SERVER_BONUS): %.o: %.c $(HEADERS_SERVER_BONUS)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_FILES_CLIENT_BONUS): %.o: %.c $(HEADERS_CLIENT_BONUS)
	@$(CC) $(CFLAGS) -c $< -o $@

make_libft:
	@$(MAKE) -C libft -s

clean:
	@rm -f $(OBJ_FILES_SERVER) $(OBJ_FILES_CLIENT)
	@rm -f $(OBJ_FILES_SERVER_BONUS) $(OBJ_FILES_CLIENT_BONUS)
	@echo "clean done"

fclean:clean
		@rm -f $(NAME) $(NAME2)
		@rm -f $(NAME_BONUS) $(NAME2_BONUS)
		@$(MAKE) fclean -C libft -s
		@echo "fclean done"

re: fclean all

.PHONY :all clean fclean re make_libft bonus