# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psimarro <psimarro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 16:23:46 by psimarro          #+#    #+#              #
#    Updated: 2023/10/27 20:01:56 by psimarro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                   PROGRAM                                    #
# **************************************************************************** #

HEADER		=	inc/push_swap.h
NAME		=	push_swap
CHECKER		=	checker

# **************************************************************************** #
#                                   COMPILER                                   #
# **************************************************************************** #

CC 			=	gcc

CFLAGS		=	-g3 #-Wall -Wextra -Werror
LDFLAGS		=	libft/libft.a

RM			=	rm -f

# **************************************************************************** #
#                                    PATHS                                     #
# **************************************************************************** #

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

SRC_DIR		=	src/
SRC			=	main.c \
				push_swap.c sort.c sort_utils.c \
				parse.c	ptr_atoi.c \
				list_func.c	list_func2.c \
				pab.c rab.c rrab.c sab.c

OBJ_DIR		=	obj/
OBJ			= 	$(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

BONUS_SRC	=	main_bonus.c \
				parse.c	ptr_atoi.c \
				list_func.c	list_func2.c \
				pab.c rab.c rrab.c sab.c

BONUS_OBJ_DIR		=	bonus_obj/
BONUS_OBJ			= 	$(addprefix $(BONUS_OBJ_DIR), $(BONUS_SRC:%.c=%.o))

VPATH 		= 	src/:src/list:src/parse:src/ops:src/sort:bonus/

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: libft $(NAME)

$(OBJ_DIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) 
	@echo "\n\033[32mCompiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

libft:
	@$(MAKE) -C libft

stack: libft
	$(CC) -o create_stack create_stack.c $(LDFLAGS)
	./create_stack a.txt
	$(RM) create_stack

pswap:
	ARG=$$(cat a.txt); ./push_swap $$ARG 
#| ./checker_Mac $$ARG

clean:
	@$(RM) -rf $(OBJ_DIR)
	@$(RM) -rf $(BONUS_OBJ_DIR)
	@$(MAKE) -C libft clean

fclean:				clean
	@$(RM) $(NAME)
	@$(RM) $(CHECKER)
	@$(MAKE) -C libft fclean
	@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\033[37m\n"

re:			fclean all

bonus:	libft $(CHECKER)

$(BONUS_OBJ_DIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(BONUS_OBJ): | $(BONUS_OBJ_DIR)

$(BONUS_OBJ_DIR):
	@mkdir -p $(BONUS_OBJ_DIR)

$(CHECKER): $(BONUS_OBJ)
	$(CC) -o $(CHECKER) $(BONUS_OBJ) $(LDFLAGS) 
	@echo "\n\033[32mBonus Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

.PHONY:		all libft stack pswap clean fclean re bonus