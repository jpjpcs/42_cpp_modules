# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/27 16:31:42 by joaosilva         #+#    #+#              #
#    Updated: 2024/10/18 09:00:41 by joaosilva        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################  Variables ######################
NAME = brain
CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -Wshadow -pedantic -std=c++98  # Compilation flags for C++98 standard and strict error checking

############  Source files - Sources to objects ###########
SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
DEPS = Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp
VPATH = src/ includes/
OBJ_PATH = obj/
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.cpp=.o))
DEPS_PATH = includes/ # Include current directory for headers

#######################   Rules ######################

# Default rule to build the executable
all: $(NAME)

# Rule to link object files and generate the executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -I $(DEPS_PATH)
	@echo "$(GREEN)Executable $(NAME) created$(DEF_COLOR)"

# Rule to compile object files from source files	
$(OBJ_PATH)%.o: %.cpp $(DEPS)
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DEPS_PATH)
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
