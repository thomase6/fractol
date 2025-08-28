# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/16 14:29:16 by texenber          #+#    #+#              #
#    Updated: 2025/08/28 09:53:25 by texenber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS1 = ft_atof.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_is_space.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_itoa.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strmapi.c \
		ft_substr.c \
		ft_strtrim.c \
		ft_split.c

NAME = libft.a
LIBC = ar rcs
CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJS = $(SRCS1:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	$(LIBC) $(NAME) $(OBJS)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
.SILENT: