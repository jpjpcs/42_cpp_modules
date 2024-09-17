# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/01 17:52:20 by joaosilva         #+#    #+#              #
#    Updated: 2024/09/16 17:52:35 by joaosilva        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################  Variables ######################
NAME = megaphone

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

#######################   Rules ######################
all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)$(NAME) created$(DEF_COLOR)"

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GRAY) Object $< compiled with success$(DEF_COLOR)"

clean:
	@$(RM) $(OBJ)
	@echo "$(RED)Object files removed$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)$(NAME) removed$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re

# Colors
DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
GRAY = \033[0;90m
