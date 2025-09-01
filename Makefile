NAME := fractol

#ingredients
SRC_DIR := src
OBJ_DIR := obj
SRCS := \
	main.c\
	window_init.c\
	mlx_utils.c\
	math_utils.c\
	fractal_render.c
SRCS := $(SRCS:%=$(SRC_DIR)/%)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR := include/libft
LIBFT_LIB := $(LIBFT_DIR)/libft.a

PRINTF_DIR := include/ft_printf
PRINTF_LIB := $(PRINTF_DIR)/libftprintf.a

MLX_DIR := include/minilibx
MLX_LIB := $(MLX_DIR)/minilibx.a

CC := cc
CFLAGS := -Wall -Werror -Wextra
CPPFLAGS := -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(PRINTF_DIR)
LIBS := -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

#utensils
RM := rm -f 
LM := make -C 
MAKEFLAGS += --no-print-directory
DIR_DUP = mkdir -p $(@D)

#recipe
all: $(LIBFT_LIB) $(MLX_LIB) $(PRINTF_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf $(LIBS) -o $@
	$(info CREATED $(NAME))

$(LIBFT_LIB):
	$(LM) $(LIBFT_DIR)

$(MLX_LIB):
	$(LM) $(MLX_DIR)

$(PRINTF_LIB):
	$(LM) $(PRINTF_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

clean:
	$(RM) $(OBJS)
	$(LM) $(LIBFT_DIR) clean
	$(LM) $(PRINTF_DIR) clean
	$(info sweep sweep)

fclean: clean
	$(RM) $(NAME)
	$(LM) $(LIBFT_DIR) fclean
	$(LM) $(PRINTF_DIR) fclean
	rm -r $(OBJ_DIR)
	$(info SWEEP SWEEP)

re:
	$(MAKE) fclean
	$(MAKE) all

#special
.PHONY: clean fclean re
.SILENT: