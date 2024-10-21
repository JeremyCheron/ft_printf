# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 16:57:15 by jcheron           #+#    #+#              #
#    Updated: 2024/10/21 10:35:12 by jcheron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME		= libftprintf.a
INCLUDE		= include
LIBFT		= libft
SRC_DIR		= src/
PRINTERS_DIR= $(SRC_DIR)/printers/
OBJ_DIR		= obj/
TEST_DIR	= tests/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I $(INCLUDE)
RM			= rm -f
AR			= ar rcs

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources

SRC_FILES	=	ft_printf
PRINTERS_FILES = ft_print_c ft_print_d ft_print_x ft_print_s ft_print_p ft_print_u ft_print_pct

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
SRC_PRINTERS= 	$(addprefix $(PRINTERS_DIR), $(addsuffix .c, $(PRINTERS_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJ_PRINTERS= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(PRINTERS_FILES)))

TEST_SRC	= $(TEST_DIR)test.c
TEST_OBJ	= $(OBJ_DIR)test.o

###

OBJF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJ) $(OBJ_PRINTERS)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@$(AR) $(NAME) $(OBJ)
			@echo -e "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo -e "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) -c $< -o $@

# Regle pour compiler les fichiers dans src/printers/
$(OBJ_DIR)%.o: $(PRINTERS_DIR)%.c | $(OBJF)
			@echo -e "$(YELLOW)Compiling printer: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) -c $< -o $@


# Ajoute cette règle pour compiler le test
$(OBJ_DIR)test.o: $(TEST_SRC) | $(OBJF)
			@echo -e "$(YELLOW)Compiling test: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -rf $(OBJ_DIR)
			@make clean -C $(LIBFT)
			@echo -e "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(LIBFT)/libft.a
			@echo -e "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"
			@echo -e "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo -e "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true

test: $(NAME) $(OBJ_DIR)test.o
			@echo -e "$(MAGENTA)Running tests...$(DEF_COLOR)"
			@$(CC) $(CFLAGS) -g -O0 -o $(TEST_DIR)test $(OBJ) $(OBJ_PRINTERS) $(OBJ_DIR)test.o -L$(LIBFT) -lft
			@./$(TEST_DIR)test

.PHONY:		all clean fclean re norm test
