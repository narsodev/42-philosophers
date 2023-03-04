# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 17:51:10 by ngonzale          #+#    #+#              #
#    Updated: 2023/03/04 18:58:59 by ngonzale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= philo

SRC_DIR		:= src
OBJ_DIR		:= obj

FILES		:= main create free routine routine_utils utils start

SRCS		:= $(addsuffix .c, $(addprefix $(SRC_DIR)/, $(FILES)))

OBJS		:= $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(FILES)))

CC			:= gcc

CFLAGS		:= -Wall -Wextra -Werror -pthread

LIBFT 	:= libft

LIB			:= -L $(LIBFT) -l ft

INCLUDE		:= -I . -I $(LIBFT)

RM			:= rm -f

all:		$(NAME)

clean:
	@echo "Removing philosophers objects..."
	@$(RM) $(OBJS)
	@$(RM) -r $(OBJ_DIR)
	@make clean -C $(LIBFT)

fclean:		clean
	@echo "Removing philosophers..."
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT)

re:			fclean all

$(NAME):	$(OBJS) | $(LIBFT)/libft.a
	$(CC) $^ $(CFLAGS) $(LIB) -o $@ 

$(LIBFT)/libft.a:
	@make -C $(LIBFT)

$(OBJS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@


$(OBJ_DIR):
	@mkdir -p $@

.PHONY: all clean fclean re
