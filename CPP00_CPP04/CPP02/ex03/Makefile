# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 17:14:21 by joaosilva         #+#    #+#              #
#    Updated: 2024/10/11 17:34:34 by joaosilva        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################  Variables ######################
NAME = fixedPoint
CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98  # Compilation flags for C++98 standard and strict error checking
INCLUDE = -I .  # Include current directory for headers

############  Source files - Sources to objects ###########
SRC = main.cpp Fixed.cpp  Point.cpp bsp.cpp # List of source files
OBJ_PATH = obj/
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.cpp=.o))

#######################   Rules ######################

# Default rule to build the executable
all: $(NAME)

# Rule to link object files and generate the executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created$(DEF_COLOR)"

# Rule to compile object files from source files
$(OBJ_PATH)%.o: %.cpp
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(GRAY)Object file $@ created$(DEF_COLOR)"

# Rule to remove object files and obj/ directory
clean:
	$(RM) $(OBJ)
	@rmdir $(OBJ_PATH) 2>/dev/null || true
	@echo "$(RED)Object files and obj/ directory removed$(DEF_COLOR)"

# Rule to remove the executable, object files, and obj/ directory
fclean: clean
	$(RM) $(NAME)
	@echo "$(RED)Executable $(NAME) removed$(DEF_COLOR)"

# Rule to remove all generated files and recompile everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re

# Colors
DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
GRAY = \033[0;90m
