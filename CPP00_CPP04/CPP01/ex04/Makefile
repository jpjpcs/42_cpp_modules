# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/14 16:11:49 by joaosilva         #+#    #+#              #
#    Updated: 2024/09/25 14:49:40 by joaosilva        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################  Variables ######################
NAME = stream_editor
CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98  # Compilation flags to enforce C++98 standard and strict error checking
INCLUDE = -I .  # Include current directory for headers

############  Source files - Sources to objects ###########
SRC = main.cpp  # Adicione aqui outros arquivos .cpp se necessário
OBJ_PATH = obj/
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.cpp=.o))

#######################   Rules ######################

# Rule to build the executable
all: $(NAME) create_test_file  # Default rule to run when make is called without arguments

# Rule to create test.txt with specified content
create_test_file:
	@echo "Hello World!" > test.txt
	@echo "Some words of this file will be replaced." >> test.txt
	@echo "And a new test.txt.replace file will be created with those words." >> test.txt
	@echo "$(GREEN)test.txt created with initial content$(DEF_COLOR)"

# Rule to link object files and generate the executable
$(NAME): $(OBJ)  # Rule to link object files and generate the executable
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created$(DEF_COLOR)"

# Rule to compile object files from source files
$(OBJ_PATH)%.o: %.cpp  # Rule to compile object files from source files
	@mkdir -p $(OBJ_PATH)  # Criar diretório se não existir
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(GRAY)Object file $@ created$(DEF_COLOR)"

# Rule to remove object files and obj/ directory
clean: 
	$(RM) $(OBJ)
	@$(RM) test.txt 2>/dev/null || true  # Remove o arquivo test.txt
	@$(RM) test.txt.replace 2>/dev/null || true  # Remove o arquivo test.txt.replace
	@rmdir $(OBJ_PATH) 2>/dev/null || true  # Remove o diretório de objetos se estiver vazio
	@echo "$(RED)Object files and test files removed$(DEF_COLOR)"

# Rule to remove the executable, object files, and obj/ directory
fclean: clean  # Rule to remove the executable and object files
	$(RM) $(NAME)
	@echo "$(RED)Executable $(NAME) removed$(DEF_COLOR)"

# Rule to remove all generated files and recompile everything
re: fclean all  # Rule to recompile everything

# Phony targets - targets that are not files
.PHONY: all create_test_file clean fclean re  # Declare targets that are not files

# Colors
DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
GRAY = \033[0;90m
