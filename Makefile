# VAR

NAME			= libft.a
LIB				= ar cr
TEST			= test

SRCS			= $(wildcard *.c)
OBJS			= $(SRCS:.c=.o)

CC				= clang
CFLAGS			= -Wall -Wextra -Werror
BSD				= -lbsd
RM				= rm -f

# RULES 

all :			$(NAME)

$(NAME) :		$(OBJS)
				$(LIB) $@ $^

$(TEST) :		$(OBJS)
				$(CC) $(CLFAGS) -o $@ $^ $(BSD)

.c.o :
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean :
				$(RM) $(OBJS)

fclean :		clean
				$(RM) $(NAME) $(TEST)

re :			clean fclean all

.PHONY :		all clean fclean re test
