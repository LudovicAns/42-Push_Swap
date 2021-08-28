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
NAME	=	push_swap

# ----- Compiling Variables ----- #
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

# ----- libft Variables ----- #
LIBFT_DIR	=	./42-Libft
LIBFT		=	$(LIBFT_DIR)/libft.a

# ----- Main Variables ----- #
SRC_DIR	=	./srcs
SRC		=	$(SRC_DIR)/push_swap.c
OBJ		=	$(SRC:.c=.o)
INC		=	-I./includes -I$(LIBFT_DIR)

# ----- Colors ----- #
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@ $(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(INC) -o $(NAME)
	@ printf "$(_SUCCESS) $(NAME) ready.\n"

$(LIBFT):
	@ printf "$(_INFO) 🔨 starting build libft.\n"
	@ $(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ printf '$(_INFO) 🔨 Compiling %s from %s.\n' "$@" "$<"

clean:
	@ $(RM) $(NAME)
	@ printf "$(_INFO) 🔥 $(NAME) removed.\n"
	@ printf "$(_SUCCESS) ✅ repository succesfully cleaned.\n"

fclean: clean
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ $(RM) $(OBJ)
	@ printf "$(_SUCCESS) 🔥 All object files has been cleaned.\n"
	@ printf "$(_SUCCESS) ✅ repository succesfully fcleaned.\n"

re: fclean all

.PHONY: all clean fclean re