NAME		=	bsq

HEADER		=	./includes/

CC			=	gcc

CFLAGS		=	-Werror -Wall -Wextra -g -I $(HEADER)

SRCS		=	srcs/main.c \
					srcs/utils/ft_putchar.c \
					srcs/utils/ft_putstr.c \
					srcs/utils/ft_strcmp.c \
					srcs/utils/ft_strlen.c \
					srcs/utils/ft_swap.c \

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean		:
				rm -rf $(OBJS)

fclean		:	clean
				rm $(NAME)

re			:	fclean all