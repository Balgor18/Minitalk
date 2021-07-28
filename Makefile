NAME = minitalk

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -rf


SRC_CLIENT=

OBJ_CLIENT=$(addprefix client_file/, ${SRC_CLIENT:.c=.o})


SRC_SERVER= main.c

OBJ_SERVER=$(addprefix server_file/, ${SRC_SERVER:.c=.o})



server : libft $(OBJ_SERVER)
			@$(CC) $(CFLAGS) -o $@ $(OBJ_SERVER) -Llibft -lft

client : libft $(OBJ_CLIENT)
			@$(CC) $(CFLAGS) -o $@ $(OBJ_CLIENT) -Llibft -lft

libft :
		make -C libft/

%.o : %.c
				$(CC) $(CFLAGS) -o $@ -c $?

all: server
	@$(CC) $(CFLAGS) -o server $(OBJ_SERVER) -Llibft -lft

norme :
		@make -C libft/ norme
		norminette -R CheckForbiddenSourceHeader $(SRC_CLIENT)
		norminette -R CheckDefine push_swap.h

clean:
				$(RM) $(OBJ_SERVER)
				$(RM) $(OBJ_CLIENT)
				@make -C libft/ clean

fclean: clean
				$(RM) server client
				@make -C libft/ fclean

re: fclean all

.PHONY: clean fclean re libft server
