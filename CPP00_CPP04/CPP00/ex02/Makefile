# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/06 14:35:08 by joaosilva         #+#    #+#              #
#    Updated: 2024/09/17 14:35:24 by joaosilva        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome do executável
NAME = account

# Arquivos fonte
SRCS = Account.cpp tests.cpp

# Geração de objetos a partir dos fontes
OBJS = $(SRCS:.cpp=.o)

# Compilador e flags
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# Regra para compilar todos os arquivos
all: $(NAME)

# Regra para compilar arquivos .cpp em .o
.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

# Regra para linkar e gerar o executável
$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

# Regra para limpar arquivos .o
clean:
	@$(RM) $(OBJS)

# Regra para limpar o executável e os arquivos .o
fclean: clean
	@$(RM) $(NAME)

# Regra para recompilar tudo
re: fclean all

# Declaração de alvos que não são arquivos
.PHONY: all clean fclean re
