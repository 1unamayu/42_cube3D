# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 14:24:44 by xamayuel          #+#    #+#              #
#    Updated: 2024/02/17 14:44:38 by xamayuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ************************ STRUCTURE ***************************************** #
# - .objs --> folder with object files
# - src ---> folder with source files
# - libraries --> folder with library files *.a
# - includes --> folder with *.h files
# **************************************************************************** #
NAME = cube3d
SRC_DIR = src
OBJ_DIR = .objs
LIBRARIES_DIR = libraries
LIBFT_DIR = src/libft
LEXER_DIR = src/lexer
LIBFT = $(LIBRARIES_DIR)/libft.a
# ------------- COLORS 
# https://talyian.github.io/ansicolors/
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
SRC =	$(SRC_DIR)/main.c
OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

CC = gcc

HEAD = -I./includes \
	   -I./$(LIBFT_DIR) 

CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address
LFLAGS = -L . $(LIBFT) 

# Address sanitizing flags
ASAN := -fsanitize=address -fsanitize-recover=address
ASAN += -fno-omit-frame-pointer -fno-common
ASAN += -fsanitize=pointer-subtract -fsanitize=pointer-compare
# Technicaly UBSan but works with ASan
ASAN += -fsanitize=undefined
# Technicaly LSan but works with ASan
# ASAN += -fsanitize=leak
# Thread sanitizing flags
TSAN := -fsanitize=thread
# Memory sanitizing flags
MSAN := -fsanitize=memory -fsanitize-memory-track-origins
RM = /bin/rm -rf

all: $(NAME)
bonus: all

$(NAME): $(OBJ) libraries libft 
		
		$(CC) $(OBJ) $(HEAD) $(CFLAGS) $(LFLAGS)  -o $(NAME)
		#$(CC) $(OBJ) $(HEAD) $(CFLAGS) $(LFLAGS) $(ASAN) -o $(NAME)
		clear
		@echo "$(LIGHT_PINK)╔════════════════════════════════════╗"
		@echo "$(LIGHT_PINK)║${PINK} 🎮🎮🎮🐶 CUBE3D COMPLETE 🐶🎮🎮🎮  ║"
		@echo "$(LIGHT_PINK)╚════════════════════════════════════╝ $(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@echo "$(GREY)Compiling.............................$(ORANGE)$(<F)"
		@$(CC) $(CFLAGS) $(HEAD)  -c $< -o $@
		@echo "$(GREEN)DONE!$(GREY)"
		@sleep .2

libraries:
	mkdir -p libraries
libft:
		@make -C $(LIBFT_DIR)

clean:
		@$(RM) $(OBJ_DIR)
		sleep .1
		clear

fclean: clean
		@$(RM) libraries/*.a
		@$(RM) $(NAME)
		sleep .1
		clear
		@echo "$(BLUE)╔════════════════════════════════════╗"
		@echo "$(BLUE)║          ${DARK_BLUE} 🗑️  ALL CLEAN 🗑️ ${BLUE}          ║"
		@echo "$(BLUE)╚════════════════════════════════════╝ $(RESET)"

re: fclean all

.PONY: all clean fclean re debug_mac debug_linux

installation: 
		@echo "$(BLUE)╔════════════════════════════════════╗"
		@echo "$(BLUE)║ ${DARK_BLUE} 🗑️  INSTALLATION COMPLETE 🗑️ ${BLUE}       ║"
		@echo "$(BLUE)╚════════════════════════════════════╝ $(RESET)"

