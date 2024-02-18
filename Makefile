# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 02:32:08 by bel-oirg          #+#    #+#              #
#    Updated: 2024/02/18 21:45:09 by bel-oirg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = ft_split.c ft_strjoin.c my_malloc.c parsed.c \
parsed_utils.c vinaya.c main.c

SRCS_B = ft_split.c ft_strjoin.c my_malloc.c parsed.c \
parsed_utils.c vinaya.c gnl.c gnl_utils.c vinaya_h.c main_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

RM = rm -f

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "[+] pipex is ready"

%.o : %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) -o $(NAME)
	@echo "[+] pipex is ready"

clean: 
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) pipex pipex_bonus

re: fclean all

.PHONY: all clean fclean re
.SILENT: all bonus fclean clean re $(OBJS) $(OBJS_B)