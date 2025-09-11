# Variables

CC= cc
CFLAGS= -Wall -Wextra -Werror -Wpedantic -Iincludes -Ilibft -Iminilibx-linux -O3
LDFLAGS= -lXext -lX11 -lm -lz
SRC= src/fractol.c src/render.c src/keys.c src/buttons.c src/iteration.c src/misc_utils.c src/struct_utils.c src/mlx_utils.c
OBJ= $(SRC:.c=.o)
NAME= fractol
LIBFT_DIR= libft
LIBFT= $(LIBFT_DIR)/libft.a
MINILIBX_DIR= minilibx-linux
MINILIBX= $(MINILIBX_DIR)/libmlx.a

# Makeflags
MAKEFLAGS += --no-print-directory -s

# Colors
RED := \033[31m
GREEN := \033[32m
YELLOW := \033[33m
BLUE := \033[34m
RESET := \033[0m

# Rules
all: $(NAME)

$(LIBFT):
	@echo "📚 ${BLUE}Compiling:${RESET} libft"
	@$(MAKE) -C $(LIBFT_DIR) bonus

$(MINILIBX):
	@echo "📚 ${BLUE}Compiling:${RESET} minilibx"
	@tar -xf ./minilibx-linux.tgz
	@$(MAKE) -C $(MINILIBX_DIR)

$(NAME): $(MINILIBX) $(OBJ) $(LIBFT) 
	@echo "💻 ${GREEN}Building:${RESET} ${NAME}"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBX) $(LDFLAGS) -o $(NAME)

%.o: %.c
	@echo "🛠️  ${BLUE}Compiling:${RESET} $< to $@"
	@$(CC) $(CFLAGS) -c $< -o $@

debug: CFLAGS += -g -o0
debug: re
	@echo "⚠️  ${RED}Compilation mode:${RESET} debug"

clean:
	@echo "🧹 ${YELLOW}Cleaning: ${RESET}project objects"
	@rm -rf $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "🧹 ${YELLOW}Cleaning: ${RESET}libft objects"
	@rm -rf $(MINILIBX_DIR)

fclean: clean
	@echo "💣 ${YELLOW}Cleaning: ${RESET}everything"
	@rm -rf $(NAME)
	@rm -rf $(MINILIBX_DIR)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus debug
