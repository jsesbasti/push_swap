# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 17:21:25 by jsebasti          #+#    #+#              #
#    Updated: 2022/11/13 22:36:02 by jsebasti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
HEADER = push_swap.h
MKFL = Makefile
OBJ_DIR = obj/
DEP_DIR = dep/

SRC= push_swap \
	Libft/ft_itoa \

# ----Libft----
Make -C Libft
# =============

# -------------
RM = rm -rf
MP = mkdir -p
CFLAGS = -Werror -Wextra -Wall -W -O3 -Ofast
LIBC = ar -rcs
# =============

# -------------
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
DEP = $(addsuffix .d, $(basename $(OBJ)))
# =============

$(OBJ_DIR)%.o: %.c $(MKFL)
	@$(MP) $(dir $@)
	${CC} $(CFLAGS) -MMD -I ./ -c $< -o $@

all:
	@$(MAKE) $(NAME)

$(NAME):: $(OBJ)
	$(LIBC) $(NAME) $(OBJ)

$(NAME)::
	@echo "Hello, i'm already compiled 😇"

-include $(DEP)

clean:
	$(RM) $(OBJ)

fclean:
	@$(MAKE) clean
	$(RM) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re