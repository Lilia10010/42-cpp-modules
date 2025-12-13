# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/13 19:32:52 by lpaula-n          #+#    #+#              #
#    Updated: 2025/12/13 19:32:53 by lpaula-n         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRCS = megaphone.cpp
OBJ_DIR = obj
OBJ			:= $(patsubst ./src/%.c, $(OBJ_DIR)/%.o, $(SRCS))

YELLOW	:= \033[1;33m
GREEN	:= \033[1;32m
BLUE	:= \033[1;34m
RED		:= \033[1;31m
RESET	:= \033[0m
NL		:= \n

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(NL)$(GREEN)Build completed successfully: $(NAME)$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS)  -c $< -o $@
	@echo  "$(YELLOW)Compiling source file:$(RESET) $(notdir $<)"

clean:
	@echo "$(NL)$(RED)Cleaning objects...$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Removing binary:$(RESET) $(NAME)"
	@$(RM) $(NAME)

.PHONY: all clean fclean re