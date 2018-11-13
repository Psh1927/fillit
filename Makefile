# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: popanase <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/20 17:22:26 by popanase          #+#    #+#              #
#    Updated: 2018/01/16 15:35:48 by popanase         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c fillit.c create_sq_list.c create_ttr_list.c solver.c case_lower_four.c copy_lists.c
#SRC = main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc -Wall -Wextra -Werror $^ -L./libft -lft -o $@ 

%.o: %.c
	gcc -Wall -Wextra -Werror -c $<

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
