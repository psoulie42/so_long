# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psoulie <psoulie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 12:48:10 by psoulie           #+#    #+#              #
#    Updated: 2024/10/18 14:05:25 by psoulie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES =		printf		\

FFILES = 	countargs	\
			putcharn	\
			putstrn		\
			putnbrn		\
			putunbrn	\
			putnbrhexn	\
			putptrn		\

SRCS = $(addprefix ./ft_, $(addsuffix .c, $(FILES)))
FSRCS_DIR = ./ffiles/
FSRCS = $(addprefix $(FSRCS_DIR)ft_, $(addsuffix .c, $(FFILES)))

OFILES = $(SRCS:.c=.o) $(FSRCS:.c=.o)

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES) $(FOFILES)
		ar rcs $(NAME) $(OFILES)

clean:
		rm -f $(OFILES)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
