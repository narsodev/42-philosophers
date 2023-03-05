# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 17:51:10 by ngonzale          #+#    #+#              #
#    Updated: 2023/03/05 14:03:16 by ngonzale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= philo

SRC_DIR			:= src
OBJ_DIR			:= obj
SRC_UTILS_DIR	:= utils
OBJ_UTILS_DIR	:= obj/utils

FILES			:= main create free routine routine_utils start \
					utils1 utils2 utils3 utils4 utils5 utils6 utils7 \
					ft_printf ft_flag_hash  \
					ft_flag_plus ft_flag_space \
					ft_flags ft_types

UTILS_FILES		:= $(addprefix $(SRC_UTILS_DIR)/, $(UTILS_FILES))
			
FILES			+= $(UTILS_FILES)

SRCS			:= $(addsuffix .c, $(addprefix $(SRC_DIR)/, $(FILES)))

OBJS			:= $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(FILES)))

CC				:= gcc

CFLAGS			:= -Wall -Wextra -Werror -pthread

INCLUDE			:= -I .

RM				:= rm -f

all:	$(NAME)

clean:
	@echo "Removing philosophers objects..."
	@$(RM) $(OBJS)
	@$(RM) -r $(OBJ_DIR)

fclean:	clean
	@echo "Removing philosophers..."
	@$(RM) $(NAME)

re:	fclean all

$(NAME):	$(OBJS)
	@echo "Compiling philosophers..."
	@$(CC) $^ $(CFLAGS) $(LIB) -o $@ 

$(OBJS):	$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/$(SRC_UTILS_DIR):
	@mkdir -p $@

.PHONY: all clean fclean re
