# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/01 17:52:20 by joaosilva         #+#    #+#              #
#    Updated: 2024/09/18 10:54:22 by joaosilva        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################  Variables ######################
NAME = megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror  -pedantic -std=c++98 # Compilation flags to enforce C++98 standard and strict error checking
# pedantic flag is used to make sure the code is written in a standard way
#INCLUDE = -I includes

############  Source files - Sources to objects ###########
SRC = megaphone.cpp

########### Object files ###########
OBJ = $(SRC:.cpp=.o) # Generation of objects from sources

############ Header files ###########
#HEADER_FILES = PhoneBook.hpp Contact.hpp
#HEADER_DIR = includes/
#HEADER = $(addprefix $(HEADER_DIR), $(HEADER_FILES))

#######################   Rules ######################
all: $(NAME) # Rule to build the executable

$(NAME): $(OBJ) # Rule to link object files and generate the executable
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)$(NAME) created$(DEF_COLOR)"

%.o: %.cpp # Rule to compile object files from source files
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GRAY) Object $< compiled with success$(DEF_COLOR)"

clean: # Rule to remove object files
	@$(RM) $(OBJ)
	@echo "$(RED)Object files removed$(DEF_COLOR)"

fclean: clean # Rule to remove the executable and object files
	@$(RM) $(NAME)
	@echo "$(RED)$(NAME) removed$(DEF_COLOR)"

re: fclean all # Rule to recompile everything

.PHONY: all clean fclean re # Declare targets that are not files

# Colors
DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
GRAY = \033[0;90m
