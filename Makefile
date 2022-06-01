# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 11:34:15 by jschneid          #+#    #+#              #
#    Updated: 2022/06/01 15:40:28 by jschneid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

MANDATORY = ft_printf.c ft_printf_percent.c ft_printf_characters.c ft_printf_pointer.c \
ft_printf_string.c ft_printf_hexadecimal.c ft_printf_numbers.c ft_printf_utils_00.c \
ft_printf_utils_01.c

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
