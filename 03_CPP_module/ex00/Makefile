# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/10 14:49:10 by microbiana        #+#    #+#              #
#    Updated: 2026/01/12 12:30:40 by microbiana       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = claptrap
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRCS = main.cpp ClapTrap.cpp
OBJ_DIR = obj
OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))

YELLOW = \033[1;33m
GREEN  = \033[1;32m
RED    = \033[1;31m
RESET  = \033[0m
NL     = \n

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NL)$(GREEN)Build completed successfully: $(NAME)$(RESET)"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiling:$(RESET) $<"

clean:
	@echo "$(NL)$(RED)Cleaning objects...$(RESET)"
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Removing binary:$(RESET) $(NAME)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
