# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shrajan <shrajan@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/08 13:24:57 by shrajan           #+#    #+#              #
#    Updated: 2026/03/08 13:25:02 by shrajan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := push_swap
BONUS   := checker
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -g
HEADER  := includes/push_swap.h

SRCS := src/main.c $(wildcard src/*/*.c)
BSRCS   := $(wildcard bonus/*.c)
OBJS    := $(SRCS:.c=.o)
BOBJS   := $(BSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(HEADER) -o $@ $^

bonus: $(BONUS)

$(BONUS): $(BOBJS) $(filter-out src/main.o,$(OBJS))
	$(CC) $(CFLAGS) -I $(HEADER) -o $@ $^

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
