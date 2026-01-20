# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjabri <mjabri@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/05 13:38:20 by mjabri            #+#    #+#              #
#    Updated: 2026/01/15 18:14:36 by mjabri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FUNC =  push_swap.c  algo.c instruction_a.c  parsing.c algo_2.c \
		algo_helpers.c  helpers.c  instruction_b.c  parsing_utils.c \
		

CFLAGS = -Wall -Werror -Wextra

OBJS = $(FUNC:.c=.o)

BONUS = checker

BFUNC = bonus/algo_helpers.c         bonus/helpers.c        bonus/parsing_utils.c \
		bonus/checker.c              bonus/instruction_a.c  bonus/push_swap.c \
		bonus/get_next_line.c        bonus/okko.c 			bonus/get_next_line_utils.c \
		bonus/parsing.c       		 bonus/instruction_b.c  bonus/checker_utils.c


BOBJ = $(BFUNC:.c=.o)

all : $(NAME)

bonus : $(BONUS)

$(BONUS) : $(BOBJ) bonus/checker.h
	cc $(CFLAGS) -o $(BONUS) $(BOBJ)

$(NAME): $(OBJS) push_swap.h
	cc $(CFLAGS) -o $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS) $(BOBJ)

fclean : clean
	rm -rf $(NAME) $(BONUS)
	
re : fclean all 

.PHONY: all clean fclean re bonus
