NAME := fractol

#ingredients
SRC_DIR := src
OBJ_DIR := obj
SRCS := \
	window.c
SRCS := $(SRCS:%=$(SRC_DIR)/%)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR := include/libft
LIBFT_LIB := $(LIBFT_DIR)/libft.a

MLX_DIR := include/minilibx
MLX_LIB := $(MLX_DIR)/minilibx.a

CC := cc
CFLAGS := -g #-Wall -Werror -Wextra
CPPFLAGS := -I$(LIBFT_DIR) -I$(MLX_DIR)
LIBS := -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

#utensils
RM := rm -f 
LM := make -C 
MAKEFLAGS += --no-print-directory
DIR_DUP = mkdir -p $(@D)

#recipe
all: $(LIBFT_LIB) $(MLX_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -L$(LIBFT_DIR) -lft $(LIBS) -o $@
	$(info CREATED $(NAME))

$(LIBFT_LIB):
	$(LM) $(LIBFT_DIR)

$(MLX_LIB):
	$(LM) $(MLX_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

clean:
	$(RM) $(OBJS)
	$(LM) $(LIBFT_DIR) clean
	$(info sweep sweep)

fclean: clean
	$(RM) $(NAME)
	$(LM) $(LIBFT_DIR) fclean
	$(info SWEEP SWEEP)

re:
	$(MAKE) fclean
	$(MAKE) all

#special
.PHONY: clean fclean re
.SILENT: