NAME = minitalk

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

# Colors
GREY = $'\x1b[30m
RED = $'\x1b[31m
GREEN = $'\x1b[32m
YELLOW = $'\x1b[33m
BLUE = $'\x1b[34m
PURPLE = $'\x1b[35m
CYAN = $'\x1b[36m
WHITE = $'\x1b[37m

SRC_CLIENT = error.c ft_putnbr_base.c init_data.c main.c treatment.c verif.c

OBJ_CLIENT = $(addprefix client_file/, ${SRC_CLIENT:.c=.o})

SRC_SERVER = main.c

OBJ_SERVER = $(addprefix server_file/, ${SRC_SERVER:.c=.o})

all : $(OBJ_SERVER) $(OBJ_CLIENT) libft lib_color
	@echo "\n$(YELLOW)Compiling server...$(WHITE)"
	$(CC) $(CFLAGS) -o server $(OBJ_SERVER) -Lincludes/libft -lft -Lincludes/lib_color -lcolor
	@echo "$(GREEN)-->[OK] $(WHITE)"
	@echo "\n$(YELLOW)Compiling client...$(WHITE)"
	$(CC) $(CFLAGS) -o client $(OBJ_CLIENT) -Lincludes/libft -lft -Lincludes/lib_color -lcolor
	@echo "$(GREEN)-->[OK] $(WHITE)\n"

lib_color :
	@echo "$(YELLOW)Compiling lib_color...$(PURPLE)"
	@make -s -C includes/lib_color/
	@echo "$(GREEN)-->[OK] $(WHITE)"

libft :
	@echo "$(YELLOW)Compiling libft...$(PURPLE)"
	@make -s -C includes/libft/
	@echo "$(GREEN)-->[OK] $(WHITE)"

%.o : %.c
	@echo "$(PURPLE)Compiling: $< $(WHITE)"
	$(CC) $(CFLAGS) -o $@ -c $?
	@echo "$(GREEN)[OK] $(WHITE)"

norme :
	make -C includes/libft/ norme
	make -C includes/lib_color/ norme
	norminette -R CheckForbiddenSourceHeader $(SRC_CLIENT)
	norminette -R CheckForbiddenSourceHeader $(SRC_SERVER)
	norminette -R CheckDefine push_swap.h

clean :
	@echo "$(RED)Clean file...$(WHITE)"
	@$(RM) $(OBJ_SERVER)
	@$(RM) $(OBJ_CLIENT)
	@make -C includes/libft/ clean
	@make -C includes/lib_color/ clean
	@echo "$(GREEN)-->[OK] $(WHITE)\n"

fclean : clean
	@echo "$(RED)Clean exec...$(WHITE)"
	$(RM) server client
	@make -C includes/libft/ fclean
	@make -C includes/lib_color/ fclean
	@echo "$(GREEN)-->[OK] $(WHITE)\n"

re : fclean all

.PHONY : clean fclean re libft server
