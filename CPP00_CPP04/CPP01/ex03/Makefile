# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/14 09:44:23 by joaosilva         #+#    #+#              #
#    Updated: 2024/09/25 14:36:37 by joaosilva        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################  Variables ######################
NAME = unnecessary_violence
CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98  # Compilation flags to enforce C++98 standard and strict error checking
INCLUDE = -I .  # Include current directory for headers

############  Source files - Sources to objects ###########
SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJ_PATH = obj/
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.cpp=.o))

#Rule to link object files and generate the executable

$(NAME): $(OBJ)  # Rule to link object files and generate the executable
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created$(DEF_COLOR)"

# Rule to compile object files from source files
$(OBJ_PATH)%.o: %.cpp  # Rule to compile object files from source files
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(GRAY)Object file $@ created$(DEF_COLOR)"

# Rule to remove object files and obj/ directory. Note the line:
# @rmdir $(OBJ_PATH) 2>/dev/null || true, que tenta remover a pasta obj/ apenas se ela estiver vazia. O 2>/dev/null || true evita erros caso a pasta já tenha sido removida ou esteja em uso.
clean: 
	$(RM) $(OBJ)
	@rmdir $(OBJ_PATH) 2>/dev/null || true
	@echo "$(RED)Object files and obj/ directory removed$(DEF_COLOR)"

# Rule to remove the executable, object files, and obj/ directory
fclean: clean  # Rule to remove the executable, object files, and obj/ directory
	$(RM) $(NAME)
	@echo "$(RED)Executable $(NAME) removed$(DEF_COLOR)"

# Rule to remove all generated files and recompile everything
re: fclean all  # Rule to recompile everything

# Phony targets - targets that are not files
.PHONY: all clean fclean re  # Declare targets that are not files

# Colors
DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
GRAY = \033[0;90m


