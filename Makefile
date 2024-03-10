NAME = pipex
VERMILION_RED=\033[1;31m
AZURE_BLUE=\033[1;34m
GOLD_COLOR=\033[38;5;220m
GREEN=\033[0;32m
RESET=\033[0m
LIB_DIR = ./libft/
LIB_FILE = $(LIB_DIR)/libft.a
SRC_FILES = src/exec.c \
			src/fork.c \
			src/free.c \
			src/main.c \
			src/parse_path.c \
			src/utils.c \

OBJECTS = $(SRC_FILES:.c=.o)
INCLUDE = ./src/pipex.h
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -I -Ilibft

all: $(NAME)  

.c.o :
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIB_FILE): 
	make -C $(LIB_DIR)

$(NAME) : $(LIB_FILE) $(OBJECTS) ./src/pipex.h Makefile
	$(CC) $(CFLAGS) -o $(NAME) -g3 -Ilibft $(OBJECTS) $(LIB_FILE)

clean:
	@echo "$(AZURE_BLUE)Cleaning in progress...$(RESET)"
	@rm -f $(OBJECTS)
	@make clean -sC $(LIB_DIR)
	@echo "$(AZURE_BLUE)Cleanup done ! :)$(RESET)"

fclean: clean
	@echo "$(AZURE_BLUE)Deep cleaning in progress...$(RESET)"
	@rm -f $(NAME)
	@make fclean -sC $(LIB_DIR)
	@echo "$(AZURE_BLUE)Deep Cleaning over ! :)$(RESET)"	

re: fclean lib $(NAME)

.PHONY: all clean fclean re lib 
