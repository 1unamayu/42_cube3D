# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 12:00:15 by xamayuel          #+#    #+#              #
#    Updated: 2024/02/22 11:19:21 by xamayuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = parser.a
SRC_DIR = 
OBJ_DIR = ../../.objs/parse
LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a
GNL_DIR = ../libft
GNL= $(GNL_DIR)/gnl.a
DESTINATION = ../../libraries/

# ------------- COLORS
RESET			= 	\033[0m
GREEN 			= 	\033[38;5;46m
WHITE 			= 	\033[38;5;15m
GREY 			= 	\033[38;5;8m
ORANGE 			= 	\033[38;5;202m
RED 			= 	\033[38;5;160m
PINK			=   \033[38;5;162m
LIGHT_PINK      =   \033[38;5;200m
BLUE			= 	\033[38;5;39m
DARK_BLUE		=   \033[38;5;57m
# -----------------SRC
SRC =	$(SRC_DIR)/ft_parse_map.c \
		$(SRC_DIR)/ft_parse_map_color.c\
		$(SRC_DIR)/ft_parse_map_texture.c \
		$(SRC_DIR)/ft_parse_map_lines.c \
		$(SRC_DIR)/ft_count_map_lines.c \
		$(SRC_DIR)/ft_parse_map_player.c\
		$(SRC_DIR)/ft_show_parse_error.c \
		$(SRC_DIR)/ft_free.c\
		$(SRC_DIR)/ft_is_region_closed.c \
		$(SRC_DIR)/ft_print_pantalla.c
		
OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))
CC = gcc
HEAD = -I ../../includes \
	   -I $(LIBFT_DIR) \
	    -I $(GNL_DIR) 
CFLAGS = -Wall -Werror -Wextra
LFLAGS = -L ./$(LIBFT_DIR) L ./$(GNL_DIR) 
RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(GNL) $(LIBFT) 
		@${MAKE} -C ../libft 
		@ar rcs ${DESTINATION}${NAME} ${OBJ}  ../../.objs/libft/*.o ../../.objs/gnl/*.o

$(OBJ_DIR)/%.o: %.c
		@mkdir -p $(OBJ_DIR)
		@echo "$(GREY)Compiling.............................$(PINK)$(<F)"
		@$(CC) $(CFLAGS) $(HEAD)  -c $< -o $@
		@echo "$(GREEN)DONE!$(GREY)"
		@sleep .2

$(LIBFT):
		@make -C $(LIBFT_DIR) 
		
$(GNL):
		@make -C $(GNL_DIR) 
clean:
		@$(RM) $(OBJ_DIR)
		sleep .1
		clear

fclean: clean
		@$(RM) ${DESTINATION}$(NAME)
		sleep .1
		clear
		@echo "$(ORANGE)╔════════════════════════════════════╗"
		@echo "$(ORANGE)║       ${DARK_BLUE} 🗑️  PARSER REMOVED 🗑️ ${ORANGE}         ║"
		@echo "$(ORANGE)╚════════════════════════════════════╝ $(RESET)"

re: fclean all

.PONY: all clean fclean re
