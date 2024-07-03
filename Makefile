CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror
RM 			= rm -rf

NAME		= libftprintf.a
OBJS		= ft_printf.o conversion_check.o conv_hexa.o conv_dec.o output.o
DEPS		= $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)
	
-include $(DEPS)

%.o:%.c
	$(CC) $(CFLAGS) -MMD -c $< 

clean:
	$(RM) $(OBJS)
	$(RM) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all