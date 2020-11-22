# VAR

NAME			= libft.a
LIB				= ar cr

BONUS			= bonus
BONUSSRCS		= $(wildcard *.c)
BONUSOBJS		= $(BONUSSRCS:.c=.o) 

TEST			= test
TESTDIR			= resources/
TESTS			= test_part1 test_additional_functions test_bonus

SRCS			= $(shell find . -name "*.c" | grep -v "lst" | grep -v "test")
OBJS			= $(SRCS:.c=.o)

CC				= clang
CFLAGS			= -Wall -Wextra -Werror
LDFLAGS			= -I . -lbsd -L. -lft
RM				= rm -f

# RULES 

all :			$(NAME)

$(NAME) :		$(OBJS)
				$(LIB) $@ $^

$(BONUS) :		$(BONUSOBJS)
				$(LIB) $(NAME) $^

$(TEST) :		$(TESTS)

$(TESTS) :		%: $(TESTDIR)%.c $(BONUS)
				$(CC) $(CLFAGS) -o $@ $< $(LDFLAGS)

.c.o :
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean :
				$(RM) $(BONUSOBJS)

fclean :		clean
				$(RM) $(NAME) $(TESTS)

re :			clean fclean all

.PHONY :		all clean fclean re test
