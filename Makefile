# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/31 20:17:48 by alejandj          #+#    #+#              #
#    Updated: 2025/06/12 12:17:52 by alejandj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iincludes -no-pie

# Directorios
LIBDIR = libft/
OBJDIR = obj/

SRC =	src/so_long.c			\
		src/so_long_utils.c		\
		src/map_utils_1.c		\
		src/map_utils_2.c		\
		src/map_check_1.c		\
		src/map_check_2.c		\
		src/map_traversal.c		\

OBJECTS = $(SRC:src/%.c=$(OBJDIR)/%.o)

# Libreria
LIBFT = $(LIBDIR)/libft.a

all: $(NAME)

# Compilar el ejecutable
$(NAME) : $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) -L$(LIBDIR) -lft -o $(NAME)

# Compilar la biblioteca
$(LIBFT):
	make -C $(LIBDIR)

# Regla para crear los .o en el directorio obj
$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJECTS)
	@echo "🧹 \033[0;32mObject files removed successfully! 🗑️\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "🚀 \033[0;32mExecutable $(NAME) has been removed! Bye bye! 👋\033[0m"

re: fclean all

.PHONY: all clean fclean re
