# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 11:34:15 by jschneid          #+#    #+#              #
#    Updated: 2022/05/24 13:55:48 by jschneid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

FLAGS = -Wall -Wextra -Werror

MANDATORY = ft_printf.c

OBJ = $(MANDATORY:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar r $(NAME) $(OBJ)
	@echo "make done"

$(OBJ): $(MANDATORY)
	@cc $(FLASG) -c $(MANDATORY)

clean:
	@/bin/rm -f $(OBJ) $(OBJB)
	@echo "make clean done"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "make fclean done"

re: fclean all
	@echo "make re done"

.PHONY:			all bonus clean fclean re
