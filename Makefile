# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/29 21:15:40 by vthomas           #+#    #+#              #
#    Updated: 2016/09/22 00:38:33 by vthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=fdf
SYS=mac
#Debugging commande (yes/no)
ifeq ($(SYS),mac)
	ARG = $(INC) $(OBJ) $(LIB_FILE) -L./mlx -lm -lmlx -I ./mlx/include \
	-framework OpenGL -framework AppKit
else
	ARG = -I /user/X11/include  $(OBJ) $(LIB_FILE) -L/usr/X11/lib -lm -lmlx\
	-lX11 -lXext
endif
DEBUG=no
CC=gcc
ifeq ($(DEBUG),yes)
	CFLAGS=-Wall -Wextra -g
else
	CFLAGS=-Wall -Wextra -Werror
endif

#* ******************************************* *#
#*                  MAIN VAR                   *#
#* These var, are listing all the files needed *#
#* and the directory where they are            *#
#* ******************************************* *#
SRC_PATH=./src/
INC_PATH=./include/
OBJ_PATH=./obj/
LIB_PATH=./

SRC_NAME=draw_grid.c\
		 event.c\
		 f_draw_line.c\
		 f_draw_linev3.c\
		 f_exit.c\
		 get_grid.c\
		 get_next_line.c\
		 main.c\
		 motion.c\
		 refresh.c

OBJ_NAME=$(SRC_NAME:.c=.o)
LIB_NAME=libft


SRC=$(addprefix $(SRC_PATH),$(SRC_NAME))
INC=$(addprefix -I, $(INC_PATH))
OBJ=$(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB=$(addprefix $(LIB_PATH),$(LIB_NAME))

# Specific to the lib utilisation (More usefull)
LIB_FILE=$(addprefix $(LIB),/$(addprefix $(LIB_NAME),.a))


#* *********************************************** *#
#*                    MAIN RULES                   *#
#* There, it's the rules who compilate the program *#
#* *********************************************** *#
all: $(NAME)
$(NAME): $(OBJ) $(LIB)
ifeq ($(DEBUG),yes)
	@echo "\033[32m[MAIN]\033[5;31m\t\t(debug)\033[0m"
else
	@echo "\033[32m[MAIN]\t\t(release)\033[0m"
endif
	@make -C mlx/
	@$(CC) $(CFLAGS) -o $(NAME) $(INC) $(ARG)

# Compilation of all .c with modulable rule
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

# Compilation of the librairie(s)
$(LIB):
	@echo "\033[34m[LIBRAIRIES]\033[0m"
	@(cd $@ && $(MAKE) re)

# Force dependance to be rebuild at all call of the rule(s)
.PHONY: clean fclean re $(LIB)
re: fclean all

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH)
	@make -C mlx $@
	@(cd $(LIB) && $(MAKE) $@)

fclean: clean
	@rm -rf $(NAME)
	@(cd $(LIB) && $(MAKE) $@)
	@echo "\nWow ! Student clean it so much !\n"

norme:
	@norminette $(SRC)
	@norminette $(addprefix $(INC_NAME),$(INC_PATH))

test: re
	@clear
	@./$(NAME) ./test/pyra.fdf
	@$(MAKE) fclean
