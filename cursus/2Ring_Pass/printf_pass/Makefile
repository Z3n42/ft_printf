# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 20:12:25 by ingonzal          #+#    #+#              #
#    Updated: 2021/08/26 13:19:53 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES = ft_printf \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putnbr_p \
		ft_putnbr_fd \
		ft_putnbr_long \
		ft_putnbr_hex \
		ft_putnbr_hexmay \

SRCS_DIR = ./
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.c.o: $(SRCS)
		$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
		$(AR) $@ $^

all: $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: clean all

.PHONY: clean fclean %.o
