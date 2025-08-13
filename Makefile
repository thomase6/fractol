NAME := fractol

#ingredients
SRC = src/main.c
OBJS = src/main.o
LIBFT_DIR = include/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

CC := cc
CFLAGS := -g -Wall -Werror -Wextra
CPPFLAGS := -I $(LIBFT_DIR)

#utensils
RM := rm -f 
LM := make -C 
MAKEFLAGS += --no-print-directory

#recipe
all: $(LIBFT_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -L$(LIBFT_DIR) -lft -o $@
	$(info CREATED $(NAME))

$(LIBFT_LIB):
	$(LM) $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

clean:
	$(RM) $(OBJS)
	$(LM) $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(LM) $(LIBFT_DIR) fclean

re:
	$(MAKE) fclean
	$(MAKE) all

#special
.PHONY: clean fclean re
.SILENT: