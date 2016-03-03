#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By:  vthomas <vthomas@student.42.fr>           +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/29 21:15:40 by vthomas           #+#    #+#             *#
#*   Updated: 2015/12/29 23:50:29 by                  ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#


NAME=fdf
#Debugging commande (yes/no)
DEBUG=yes
CC=gcc
ifeq ($(DEBUG),yes)
	export CFLAGS=-g
else
	export CFLAGS=-Wall -Wextra -Werror
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

SRC_NAME=main.c\
		 f_distance.c\
		 f_draw_line.c\
		 f_draw_linefade.c\
		 f_draw_pixelintensity.c\
		 f_draw_poly.c\
		 f_exit.c\
		 f_new_coord.c\
		 f_new_poly.c

INC_NAME=$(wildcard *.h)
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
$(NAME):$(OBJ) $(LIB)
ifeq ($(DEBUG),yes)
	@echo "[MAIN]\t\t(debug)"
else
	@echo "[MAIN]\t\t(release)"
endif
	@$(CC) $(CFLAGS) -o $(NAME) $(INC) $(OBJ) $(LIB_FILE) -lm\
		-lmlx -framework OpenGL -framework AppKit

# Compilation of all .c with modulable rule
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

# Compilation of the librairie(s)
$(LIB):
	@echo "[LIBRAIRIES]"
	@(cd $@ && $(MAKE) re)

# Force dependance to be rebuild at all call of the rule(s)
.PHONY: clean fclean re $(LIB)
re: fclean all

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -rf $(NAME)
	@echo "\nWow ! Student clean it so much !\n"

norme:
	@norminette $(SRC)
	@norminette $(addprefix $(INC_NAME),$(INC_PATH))

test: re
	@clear
	@./$(NAME) | cat -e
	@(cd ./ && $(MAKE) fclean)
