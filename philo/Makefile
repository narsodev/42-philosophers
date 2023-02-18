# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 17:51:10 by ngonzale          #+#    #+#              #
#    Updated: 2023/02/18 20:01:32 by ngonzale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= philo

SRC_DIR		:= src
OBJ_DIR		:= obj

FILES		:= main create free routine

SRCS		:= $(addsuffix .c, $(addprefix $(SRC_DIR)/, $(FILES)))

OBJS		:= $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(FILES)))

SRCS_NUM	:= $(words $(SRCS))
OBJS_CREATED:= $(shell if [ -d $(OBJ_DIR) ]; then ls -l $(OBJ_DIR)/* | grep -c "\.o"; else echo 0; fi)

CC			:= gcc

CFLAGS		:= -Wall -Wextra -Werror -pthread -g # -fsanitize=thread

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
	@$(eval OBJS_CREATED = 0)
	@make fclean -C $(LIBFT)

re:			fclean all

$(NAME):	$(OBJS) | $(LIBFT)/libft.a
	@echo "Compiling philosophers..."
	$(CC) $(CFLAGS) $(LIB) $^ -o $@ 

$(LIBFT)/libft.a:
	@make -C $(LIBFT)

$(OBJS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(eval OBJS_CREATED = $(shell expr $(OBJS_CREATED) + 1))
	@printf "Making philosophers object $(OBJS_CREATED)/$(SRCS_NUM)...\r"
	@if [ $(OBJS_CREATED) = $(SRCS_NUM) ]; then echo ""; fi
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@


$(OBJ_DIR):
	@mkdir -p $@

.PHONY: all clean fclean re
