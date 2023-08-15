# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psimarro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 16:23:46 by psimarro          #+#    #+#              #
#    Updated: 2023/08/15 12:00:13 by psimarro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                   PROGRAM                                    #
# **************************************************************************** #

INC_DIR	= inc/
HEADER	= inc/push_swap.h
NAME	= push_swap

# **************************************************************************** #
#                                   COMPILER                                   #
# **************************************************************************** #

CC 		= gcc

CFLAGS	= -Wall -Wextra -Werror -glldb
LDFLAGS = Libft/libft.a

RM		= rm -f

# **************************************************************************** #
#                                    PATHS                                     #
# **************************************************************************** #

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

SRC_DIR				=	src/
SRC =	main.c		\
		push_swap.c \
		ptr_atoi.c	\
		parse.c		\
		list_func.c	\
		list_func2.c\
		pab.c \
		rab.c	\
		rrab.c		\
		sab.c

OBJ_DIR				=	obj/
OBJ					= 	$(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))
VPATH 				= 	src/:src/list:src/parse:src/ops

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: $(NAME)

$(OBJ_DIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): libft $(OBJ)
	$(CC) -o $(NAME) $(LDFLAGS) $(OBJ)
	@echo "\n\033[32mCompiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

libft:
	@$(MAKE) -C Libft

stack: libft
	$(CC) -o create_stack create_stack.c $(LDFLAGS)
	./create_stack a.txt
	$(RM) create_stack

pswap:
	ARG=$$(cat a.txt); ./push_swap $$ARG | ./checker_Mac $$ARG

clean:
	@$(RM) -rf $(OBJ_DIR)
	@$(MAKE) -C Libft clean

fclean:				clean
	@$(RM) $(NAME)
	@$(MAKE) -C Libft fclean
	@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\033[37m\n"

re:			fclean all

bonus:		re

.PHONY:		all libft stack pswap clean fclean re bonus