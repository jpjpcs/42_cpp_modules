# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/27 16:31:42 by joaosilva         #+#    #+#              #
#    Updated: 2024/10/18 11:17:49 by joaosilva        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################  Variables ######################
NAME = abstractAnimal
CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98  # Flags de compilação para C++98

############  Source files - Sources to objects ###########
SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp
DEPS = Animal.hpp Dog.hpp Cat.hpp
OBJ_PATH = obj/
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.cpp=.o))
DEPS_PATH = ./  # Incluir o diretório atual para headers

#######################   Rules ######################

# Regra padrão para construir o executável
all: $(NAME)

# Regra para compilar arquivos-objeto e gerar o executável
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -I $(DEPS_PATH)
	@echo "$(GREEN)Executable $(NAME) created$(DEF_COLOR)"

# Regra para compilar arquivos objeto a partir dos fontes
$(OBJ_PATH)%.o: %.cpp $(DEPS)
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DEPS_PATH)
	@echo "$(GRAY)Object file $@ created$(DEF_COLOR)"

# Regra para remover arquivos-objeto e diretório obj/
clean:
	$(RM) $(OBJ)
	@rmdir $(OBJ_PATH) 2>/dev/null || true
	@echo "$(RED)Object files and obj/ directory removed$(DEF_COLOR)"

# Regra para remover o executável e os arquivos-objeto
fclean: clean
	$(RM) $(NAME)
	@echo "$(RED)Executable $(NAME) removed$(DEF_COLOR)"

# Regra para recompilar tudo
re: fclean all

# Targets "phony"
.PHONY: all clean fclean re

# Cores
DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
GRAY = \033[0;90m
