NAME = pipex.a
SRC_DIR = src/
OBJ_DIR = obj/
FLAGS = -Werror -Wextra -Wall
PRINTF = Printf/
CC = gcc
AR = ar rcs
SRC_FILES = main\
			utils\
			open_files\
			path_check
GNL_DIR = GNL/
DEF_COLOR = \033[0;80m
GREEN = \033[0;92m

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all: $(NAME)

OBJF = .cache_exists

$(NAME): $(OBJ)
	@make -C Printf/
	@$(AR) $(NAME) $(OBJ) 
	@$(CC) $(NAME) $(FLAGS) Printf/libftprintf.a pipex.a -o pipex
	@echo "$(GREEN)pipex compiled$(DEF_COLOR)"

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c | $(OBJF)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -r $(OBJ_DIR)
	@rm -rf a.out
	@make clean -C $(PRINTF)

fclean: clean
	@rm -f $(NAME)
	@rm -rf pipex
	@make fclean -C $(PRINTF)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx