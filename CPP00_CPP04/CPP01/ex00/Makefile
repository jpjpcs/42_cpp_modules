# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/07 20:12:07 by joaosilva         #+#    #+#              #
#    Updated: 2024/09/18 10:54:01 by joaosilva        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################  Variables ######################
NAME = zombies
RM = rm -f
CC = c++
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98 # Compilation flags to enforce C++98 standard and strict error checking
# pedantic flag is used to make sure the code is written in a standard way
#INCLUDE = -I includes

############  Source files - Sources to objects ###########
SRC_FILES = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
SRC_DIR = .
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

########### Object files ###########
OBJ_DIR = obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o)) # Generation of objects from sources

############ Header files ###########
#HEADER_FILES = PhoneBook.hpp Contact.hpp
#HEADER_DIR = includes/
#HEADER = $(addprefix $(HEADER_DIR), $(HEADER_FILES))

#######################   Rules ######################
all: $(NAME) # Rule to build the executable

$(NAME): $(OBJS) # Rule to link object files and generate the executable
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)Executable $(NAME) created$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)/%.cpp # Rule to compile object files from source files
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GRAY)Object file $@ created$(DEF_COLOR)"

clean: # Rule to remove object files
	@$(RM) $(OBJS)
	@$(RM) -r $(OBJ_DIR)
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
