# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 00:21:11 by joaosilva         #+#    #+#              #
#    Updated: 2024/09/20 00:29:28 by joaosilva        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################  Variables ######################
NAME = brain
CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98  # Flags de compilação

############  Source files - Sources to objects ###########
SRC_FILES = main.cpp
SRC_DIR = .
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

########### Object files ###########
OBJ_DIR = obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))

#######################   Rules ######################
all: $(NAME)  # Regra para compilar o executável

$(NAME): $(OBJS)  # Regra para ligar os ficheiros objeto e criar o executável
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)Executável $(NAME) criado$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)/%.cpp  # Regra para compilar ficheiros objeto a partir do código-fonte
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GRAY)Ficheiro objeto $@ criado$(DEF_COLOR)"

clean:  # Regra para remover os ficheiros objeto
	@$(RM) $(OBJS)
	@$(RM) -r $(OBJ_DIR)
	@echo "$(RED)Ficheiros objeto removidos$(DEF_COLOR)"

fclean: clean  # Regra para remover o executável e os ficheiros objeto
	@$(RM) $(NAME)
	@echo "$(RED)$(NAME) removido$(DEF_COLOR)"

re: fclean all  # Regra para recompilar tudo

.PHONY: all clean fclean re  # Declarar targets que não são ficheiros

# Cores
DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
GRAY = \033[0;90m
