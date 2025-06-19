# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/31 20:17:48 by alejandj          #+#    #+#              #
#    Updated: 2025/06/19 16:13:04 by alejandj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iincludes -I$(MINILIBXDIR)

# Directorios
LIBDIR = libft/
MINILIBXDIR = minilibx-linux
OBJDIR = obj/

SRC =	src/so_long.c			\
		src/so_long_utils.c		\
		src/map_utils_1.c		\
		src/map_utils_2.c		\
		src/map_check_1.c		\
		src/map_check_2.c		\
		src/window.c			\
		src/events.c			\
		src/render.c			\

OBJECTS = $(SRC:src/%.c=$(OBJDIR)/%.o)

# Librerias
LIBFT = $(LIBDIR)/libft.a
MINILIBX = $(MINILIBXDIR)/libmlx.a

all: $(NAME)

# Compilar el ejecutable
$(NAME): $(OBJECTS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) -L$(LIBDIR) -lft -L$(MINILIBXDIR) -lmlx -lXext -lX11 -lm

# Compilar libft
$(LIBFT):
	make -C $(LIBDIR) all

# Compilar minilibx
$(MINILIBX):
	make -C $(MINILIBXDIR) all
	
# Regla para crear los .o en el directorio obj
$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJECTS)
	make -C $(LIBDIR) clean
	make -C $(MINILIBXDIR) clean
	@echo "🧹 \033[0;32mObject files removed successfully! 🗑️\033[0m"

fclean: clean
	@rm -rf $(NAME)
	make -C $(LIBDIR) fclean
	@echo "🚀 \033[0;32mExecutable $(NAME) has been removed! Bye bye! 👋\033[0m"

re: fclean all

.PHONY: all clean fclean re