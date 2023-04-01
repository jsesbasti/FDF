# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 17:21:25 by jsebasti          #+#    #+#              #
#    Updated: 2023/03/31 22:43:41 by jsebasti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
INC_DIR		= inc/
MKFL		= Makefile
OBJ_DIR		= obj/


# ----Libraryes----
PW_HEADER	= $(INC_DIR)/fdf.h
LIB			= Libs/Libft/libft.a
LIB_M 		= Libs/Libft/
PRINTF		= Libs/printf/libftprintf.a
PRINTF_M	= Libs/printf/
MLX 		= Libs/minilibx_macos/libmlx.a
MLX_M		= Libs/minilibx_macos
# =============

# -------------
RM = rm -rf
MP = mkdir -p
CFLAGS = -Werror -Wextra -Wall -O2 #-fsanitize=address
MLX_FLAGS = -lmlx -L $(MLX_M) -framework OpenGL -framework AppKit
LIBC = ar -rcs
# =============

SRC	=	src/fdf.c 			\
		src/fdf_utils.c  	\
		src/fdf_utils2.c		\

# -------------
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
DEP = $(addsuffix .d, $(basename $(OBJ)))
# =============

$(OBJ_DIR)%.o: %.c $(MKFL)
	@$(MP) $(dir $@)
	$(CC) $(CFLAGS) -Imlx -MMD -I $(INC_DIR) -c $< -o $@

all:
	@$(MAKE) -C $(MLX_M)
	@$(MAKE) -C $(LIB_M)
	@$(MAKE) -C $(PRINTF_M)
	@$(MAKE) $(NAME)

$(NAME):: $(OBJ) $(LIB) $(PRINTF) $(MLX)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) $(LIB) $(PRINTF) $(MLX) -o $(NAME)

$(NAME)::
	@echo "Hello, FdF already compiled 😇"

-include $(DEP)

clean:
	@$(MAKE) clean -C $(LIB_M)
	@$(MAKE) clean -C $(PRINTF_M)
	@$(MAKE) clean -C $(MLX_M)
	$(RM) $(OBJ_DIR)
	$(RM) $(NAME)

fclean: clean
	@$(MAKE) fclean -C $(LIB_M)
	@$(MAKE) fclean -C $(PRINTF_M)
	$(RM) $(OBJ_DIR)
	$(RM) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE)

.PHONY: all clean fclean re
