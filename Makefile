# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lanselin <lanselin@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/28 16:25:22 by lanselin          #+#    #+#              #
#    Updated: 2021/08/28 16:25:22 by lanselin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----- Names ----- #
NAME			=	push_swap
NAME_MAIN		=	$(SRC_DIR)/push_swap.c
CHECKER			=	checker
CHECKER_MAIN	=	$(SRC_DIR)/checker.c

# ----- Compiling Variables ----- #
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

# ----- libft Variables ----- #
LIBFT_DIR	=	./42-Libft
LIBFT		=	$(LIBFT_DIR)/libft.a

# ----- Main Variables ----- #
SRC_DIR		=	./srcs
SRC			=	$(SRC_DIR)/push_swap_utils1.c \
				$(SRC_DIR)/push_swap_utils2.c \
				$(SRC_DIR)/instructions.c \
				$(SRC_DIR)/chunk_utils1.c \
				$(SRC_DIR)/lstchunk_utils1.c \
				$(SRC_DIR)/utils.c
OBJ			=	$(SRC:.c=.o)
CHECKER_OBJ	=	$(CHECKER_SRC:.c=.o)
INC			=	-I./includes \
				-I$(LIBFT_DIR) \
				-I$(LIBFT_DIR)/stack \
				-I$(LIBFT_DIR)/gnl

# ----- Colors ----- #
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@ $(CC) $(CFLAGS) $(OBJ) $(NAME_MAIN) $(LIBFT) $(INC) -o $(NAME)
	@ printf "$(_SUCCESS) $(NAME) ready.\n"

$(CHECKER): $(LIBFT) $(CHECKER_OBJ)
	@ $(CC) $(CFLAGS) $(OBJ) $(CHECKER_OBJ) $(CHECKER_MAIN) $(LIBFT) $(INC) -o $(CHECKER)
	@ printf "$(_SUCCESS) $(CHECKER) ready.\n"

$(LIBFT):
	@ printf "$(_INFO) 🔨 starting build libft.\n"
	@ $(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@ $(CC) $(CFLAGS) $(INC) -c $< -o $@
	@ printf '$(_INFO) 🔨 Compiling %s from %s.\n' "$@" "$<"

clean:
	@ $(RM) $(NAME)
	@ printf "$(_INFO) 🔥 $(NAME) removed.\n"
	@ $(RM) $(CHECKER)
	@ printf "$(_INFO) 🔥 $(CHECKER) removed.\n"
	@ printf "$(_SUCCESS) ✅ repository succesfully cleaned.\n"

fclean: clean
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ $(RM) $(OBJ) $(CHECKER_OBJ)
	@ printf "$(_SUCCESS) 🔥 All object files has been cleaned.\n"
	@ printf "$(_SUCCESS) ✅ repository succesfully fcleaned.\n"

re: fclean all

bonus: $(CHECKER)

.PHONY: all clean fclean re