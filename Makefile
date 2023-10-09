# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 11:26:53 by mafranco          #+#    #+#              #
#    Updated: 2023/10/09 21:16:03 by mafranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
FTPRINTF = ./ftprintf/libftprintf.a
RM = rm -rf

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
	@make -C ./libft
$(FTPRINTF):
	@make -C ./ftprintf

$(SERVER): $(SV_OBJS) $(LIBFT) $(FTPRINTF)
	@$(CC) $(CFLAGS) $(SV_OBJS) $(LIBFT) $(FTPRINTF) -o server
	@echo "$(GREEN)server created$(RESET)"

$(CLIENT): $(CLIENT_OBJS) $(LIBFT) $(FTPRINTF)
	@$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT) $(FTPRINTF) -o client
	@echo "$(GREEN)client created$(RESET)"
	
clean:
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./ftprintf
	@$(RM) $(SV_OBJS) $(CLIENT_OBJS)
	@echo "$(YELLOW)objects deleted$(RESET)"

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(MAKE) fclean -C ./ftprintf
	@$(RM) $(SERVER) $(CLIENT)
	@echo "$(YELLOW)server and client deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re
