# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 02:32:08 by bel-oirg          #+#    #+#              #
#    Updated: 2024/02/19 17:36:01 by bel-oirg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_B = pipex_bonus

SRCS = ft_split.c ft_strjoin.c my_malloc.c parsed.c \
parsed_utils.c vinaya.c main.c

SRCS_B = ft_split_bonus.c ft_strjoin_bonus.c \
		my_malloc_bonus.c parsed_bonus.c \
		parsed_utils_bonus.c vinaya_bonus.c \
		gnl_bonus.c gnl_utils_bonus.c vinaya_h_bonus.c main_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS) : pipex.h
$(OBJS_B) : pipex_bonus.h

bonus: $(NAME_B)

$(NAME_B) : $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) -o $(NAME_B)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) pipex pipex_bonus

re: fclean all

.PHONY: all clean fclean re