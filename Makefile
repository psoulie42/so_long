# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 11:01:32 by psoulie           #+#    #+#              #
#    Updated: 2025/01/18 16:45:07 by psoulie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BOLD = \033[1m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RED = \033[0;31m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
COLOUR_RESET = \033[0m

SRCSDIR = srcs/
ODIR = obj/
MLXDIR = minilibx-linux/
UTILS = utils/
GNL = $(UTILS)get_next_line/
PRINTF = $(UTILS)ft_printf/

FILES = main										\
		window										\
		map											\
		map_parsing									\
		$(UTILS)ft_strstr							\
		$(GNL)get_next_line							\
		$(GNL)get_next_line_utils					\
		$(PRINTF)ft_printf							\
		$(PRINTF)ffiles/ft_countargs				\
		$(PRINTF)ffiles/ft_putcharn					\
		$(PRINTF)ffiles/ft_putnbrhexn				\
		$(PRINTF)ffiles/ft_putnbrn					\
		$(PRINTF)ffiles/ft_putptrn					\
		$(PRINTF)ffiles/ft_putstrn					\
		$(PRINTF)ffiles/ft_putunbrn					\

AMLX = libmlx_Linux.a
MLXLIB = $(MLXDIR)$(AMLX)

SRCS = $(addprefix $(SRCSDIR), $(addsuffix .c, $(FILES)))
OFILES = $(addprefix $(ODIR), $(addsuffix .o, $(FILES)))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

NAME = so_long

.PHONY: all clean fclean re

all: $(NAME)

$(MLXLIB):
	@echo "$(BLUE)$(BOLD)💾 Compiling MLX library...$(COLOUR_RESET)"
	@make -C $(MLXDIR)

$(ODIR)%.o: $(SRCSDIR)%.c
	@mkdir -p $(ODIR) $(ODIR)$(UTILS) $(ODIR)$(GNL) $(ODIR)$(PRINTF) $(ODIR)$(PRINTF)ffiles/
	@echo "$(YELLOW)$(BOLD)💾 Compiling $<...$(COLOUR_RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OFILES) $(MLXLIB)
	@echo "$(YELLOW)$(BOLD)Executable: $@$(COLOUR_RESET)"
	$(CC) $(CFLAGS) $(OFILES) $(MLXLIB) -lX11 -lXext -lm -o $(NAME)
	@echo "$(GREEN)$(BOLD)🎊 Compilation complete! 🎊$(COLOUR_RESET)"

clean:
	@echo "$(RED)$(BOLD)🧹 Removing object files...$(COLOUR_RESET)"
	rm -rf $(ODIR)
	@make -C $(MLXDIR) clean
	@echo "$(GREEN)$(BOLD)✔️ Object files removed!$(COLOUR_RESET)"

fclean: clean
	@echo "$(RED)$(BOLD)🗑️  Removing executable $(NAME)...$(COLOUR_RESET)"
	rm -f $(NAME)
	@make -C $(MLXDIR) clean
	@echo "$(GREEN)$(BOLD)✨ All clean! ✨$(COLOUR_RESET)"

party:
	@echo "$(BOLD)Let's party!"
	@echo "$(RED)$(BOLD)  (^-^) $(COLOUR_RESET)"
	@sleep 0.5
	@echo "$(CYAN)$(BOLD) \\(^-^\\) $(COLOUR_RESET)"
	@sleep 0.5
	@echo "$(YELLOW)$(BOLD)  (^-^)  $(COLOUR_RESET)"
	@sleep 0.5
	@echo "$(BLUE)$(BOLD) (/^-^)/ $(COLOUR_RESET)"
	@sleep 0.5
	@echo "$(MAGENTA)$(BOLD)  (^-^)  $(COLOUR_RESET)"
	@sleep 0.5
	@echo "$(GREEN)$(BOLD) \\(^-^)/ $(COLOUR_RESET)"
	@sleep 0.5
	@echo "$(BOLD)Party time is over! Back to work! \n  (^-^)7$(COLOUR_RESET)"

re: fclean all
