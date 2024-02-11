# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 02:32:08 by bel-oirg          #+#    #+#              #
#    Updated: 2024/02/11 23:12:12 by bel-oirg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_B = pipex_bonus

SRCS = ft_split.c ft_strjoin.c my_malloc.c parsed.c \
parsed_utils.c vinaya.c

SRCS_B = $(SRCS) gnl.c gnl_utils.c vinaya_h.c

CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

RM = rm -f

all: $(NAME)

$(NAME) : $(SRCS) main.c pipex.h
	$(CC) $(CFLAGS) $(SRCS) main.c -o pipex

bonus: $(NAME_B)

$(NAME_B) : $(SRCS_B) main_bonus.c pipex_bonus.h
	$(CC) $(CFLAGS) $(SRCS_B) main_bonus.c -o pipex_bonus

clean: 
	@echo "nothing to clean"

fclean:
	$(RM) pipex pipex_bonus

re: fclean all

.PHONY: all clean fclean re