# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/01 16:06:30 by joaosilva         #+#    #+#              #
#    Updated: 2024/09/16 16:28:58 by joaosilva        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################  Variables ######################
NAME = phonebook
CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDE = -I includes

############  Source files - Sources to objects ###########
SRC_FILES = main.cpp PhoneBook.cpp Contact.cpp
SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

########### Object files ###########
OBJ_DIR = obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))

############ Header files ###########
HEADER_FILES = PhoneBook.hpp Contact.hpp
HEADER_DIR = includes/
HEADER = $(addprefix $(HEADER_DIR), $(HEADER_FILES))

#######################   Rules ######################
all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJS)
	@echo "Executable $(NAME) created"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "Object file $@ created"

clean:
	@$(RM) $(OBJS)
	@$(RM) -r $(OBJ_DIR)
	@echo "Object files removed"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) removed"

re: fclean all

.PHONY: all clean fclean re