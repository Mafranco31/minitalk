# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafranco <mafranco@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 17:45:19 by mafranco          #+#    #+#              #
#    Updated: 2023/10/09 21:15:03 by mafranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIB = src/libft.h

SRC = src/ft_atoi.c

OBJ	=	$(SRC:.c=.o)

CC	=	cc

RM	=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -I.

SRC_DIR =	src

GREEN	= \033[1;32m
YELLOW	= \033[1;33m
RESET	= \033[0m


all: $(NAME) 

%.o: %.c $(LIB)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIB)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)libft.a compiled$(RESET)"

clean:
	@$(RM) -r $(SRC_DIR)/*.o

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
