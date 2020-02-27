# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 19:50:49 by lcabanes          #+#    #+#              #
#    Updated: 2019/07/08 19:16:17 by lcabanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS =	-Wall -Wextra -Werror
CPPFLAGS =	-I./includes

HEAD = ./includes/print_memory.h

NAME = memory_reader.out

#==========

SRC_PATH = ./srcs

SRC_NAME = main_mem_read.c\
			print_memory.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = ./objs

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

#==========

BENCH_NAME = running_program.out

SRC_BENCH_PATH = ./bench_test

SRC_BENCH_NAME = main_running_program.c

SRC_BENCH = $(addprefix $(SRC_BENCH_PATH)/,$(SRC_BENCH_NAME))

#==========

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEAD) | $(OBJ_PATH)
	gcc -c -o $@ $(CFLAGS) $(CPPFLAGS) $<

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

bench: $(SRC_BENCH)
	gcc -o $(BENCH_NAME) $(CFLAGS) $(SRC_BENCH)

clean:
	rm -f $(OBJ)
	rm -df $(OBJ_PATH)
	rm -f $(BENCH_NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bench
