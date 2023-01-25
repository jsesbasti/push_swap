# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 17:21:25 by jsebasti          #+#    #+#              #
#    Updated: 2023/01/25 05:41:29 by jsebasti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
INC_DIR		= inc/
MKFL		= Makefile
OBJ_DIR		= obj/


# ----Libraryes----
PW_HEADER	= $(INC_DIR)/push_swap.h
PW_HEADER 	+= $(INC_DIR)/moves.h
LIB			= Libs/Libft/libft.a
LIB_M 		= Libs/Libft/
PRINTF		= Libs/printf/libftprintf.a
PRINTF_M	= Libs/printf/
# =============

# -------------
RM = rm -rf
MP = mkdir -p
CFLAGS = -Werror -Wextra -Wall -W -O3 -Ofast
LIBC = ar -rcs
# =============

SRC	=	src/big_algor.c 	\
		src/check.c 		\
		src/init_stacks.c	\
		src/push_swap.c		\
		src/threetofive.c	\
		src/push.c 			\
		src/rotate.c 		\
		src/rrotate.c 		\
		src/swap.c 			\
		utils/errors.c		\
		utils/pw_utils.c	\
		utils/sort_utils.c	\

# -------------
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
DEP = $(addsuffix .d, $(basename $(OBJ)))
# =============

$(OBJ_DIR)%.o: %.c $(MKFL)
	@$(MP) $(dir $@)
	$(CC) $(CFLAGS) -MMD -I ./inc -c $< -o $@

all:
	@$(MAKE) -C $(LIB_M)
	@$(MAKE) -C $(PRINTF_M)
	@$(MAKE) $(NAME)

$(NAME):: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(PRINTF) -o $(NAME)

$(NAME)::
	@echo "Hello, i'm already compiled 😇"

-include $(DEP)

clean:
	$(MAKE) clean -C $(LIB_M)
	$(MAKE) clean -C $(PRINTF_M)
	$(RM) $(OBJ_DIR)
	$(RM) $(NAME)

fclean:
	$(MAKE) fclean -C $(LIB_M)
	$(MAKE) fclean -C $(PRINTF_M)
	$(RM) $(OBJ_DIR)
	$(RM) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE)

.PHONY: all clean fclean re
