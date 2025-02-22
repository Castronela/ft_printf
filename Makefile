CC 			:= gcc -g
CFLAGS 		:= -Wall -Wextra -Werror -MMD
RM 			:= rm -rf

RESET 		:= 	\033[0m
GREEN 		:= 	\033[32m
RED 		= 	\033[31m

D_SRC		:= src
D_OBJ		:= obj
D_INC		:= include

SRC			:= ft_printf.c\
				utils.c\
				libft_utils.c \
				lst_string.c \
				flags.c \
				chars.c \
				numbers.c \
				assemble_print.c
OBJ			:= $(addprefix $(D_OBJ)/, $(SRC:.c=.o))
DEP			:= $(addprefix $(D_OBJ)/, $(SRC:.c=.d))

VPATH		:= $(D_SRC)

NAME		:= libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ) && echo Library file "$(GREEN)$(NAME)$(RESET)" is ready
	
-include $(DEP)

$(D_OBJ)/%.o:%.c | $(D_OBJ)
	@$(CC) $(CFLAGS) -I$(D_INC) -c $< -o $@

$(D_OBJ): 
	@mkdir -p $@

clean:
	@$(RM) $(D_OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re run