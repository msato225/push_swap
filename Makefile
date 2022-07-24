PUSH_SWAP = push_swap

SRCS = pushswap.c quicksort.c action.c checker.c execute.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all				:	$(PUSH_SWAP)

$(PUSH_SWAP)	:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PUSH_SWAP)

clean			:
	rm -rf $(OBJS)

fclean			:	clean
	rm -rf $(PUSH_SWAP)

re				:	fclean all

.PHONY: all clean fclean re