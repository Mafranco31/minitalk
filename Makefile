# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 11:26:53 by mafranco          #+#    #+#              #
#    Updated: 2023/10/10 17:38:50 by mafranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./lib/libft/libft.a
FTPRINTF = ./lib/ftprintf/libftprintf.a
RM = rm -rf

LIBFT_PATH	=	./lib/libft
FTPRINTF_PATH	=	./lib/ftprintf

SERVER = server
CLIENT = client

SV_SRCS = src/server.c
SV_OBJS = $(SV_SRCS:.c=.o)

CLIENT_SRCS = src/client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

GREEN	=	\033[1;32m
YELLOW	=	\033[1;33m
RESET	=	\033[0m

all: $(SERVER) $(CLIENT)

$(LIBFT):
	@make -s -C $(LIBFT_PATH)
$(FTPRINTF):
	@make -s -C $(FTPRINTF_PATH)

$(SERVER): $(SV_OBJS) $(LIBFT) $(FTPRINTF)
	@$(CC) $(CFLAGS) $(SV_OBJS) $(LIBFT) $(FTPRINTF) -o server
	@echo "$(GREEN)server created$(RESET)"

$(CLIENT): $(CLIENT_OBJS) $(LIBFT) $(FTPRINTF)
	@$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT) $(FTPRINTF) -o client
	@echo "$(GREEN)client created$(RESET)"
	
clean:
	@make -s clean -C $(LIBFT_PATH)
	@make -s clean -C $(FTPRINTF_PATH)
	@$(RM) $(SV_OBJS) $(CLIENT_OBJS)
	@echo "$(YELLOW)objects deleted$(RESET)"

fclean: clean
	@make -s fclean -C $(LIBFT_PATH)
	@make -s fclean -C $(FTPRINTF_PATH)
	@$(RM) $(SERVER) $(CLIENT)
	@echo "$(YELLOW)server and client deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re
