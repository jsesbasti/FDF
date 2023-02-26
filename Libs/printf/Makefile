# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 21:24:52 by jsebasti          #+#    #+#              #
#    Updated: 2023/02/03 11:06:59 by jsebasti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER = ft_printf.h
MKFL	= Makefile
NAME = libftprintf.a

OBJ_DIR	= obj/

SRC =	ft_printf.c \
		src/ft_print_char.c \
		src/ft_print_str.c \
		src/ft_print_digits.c \
		src/ft_print_pointers.c \
		src/ft_print_unsigned.c \
		src/ft_print_hexa_low.c \
		src/ft_print_hexa_up.c

RM = rm -rf
MP	= mkdir -p

CFLAGS = -Werror -Wall -Wextra -W -O3 -Ofast 

LIBC = ar -rcs

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
DEP	= $(addsuffix .d, $(basename $(OBJ)))

$(OBJ_DIR)%.o: %.c $(MKFL)
	@$(MP) $(dir $@)
	${CC} ${CFLAGS} -MMD -I ./ -c $< -o $@

all:
	@$(MAKE) $(NAME)

$(NAME):: $(OBJ)
	$(LIBC) $(NAME) $(OBJ)

$(NAME)::
	@echo "Hello, Printf already compiled 😇"

-include $(DEP)

clean:
	$(RM) $(OBJ) $(OBJ_DIR)

fclean:
	@$(MAKE) clean
	$(RM) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
