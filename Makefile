NAME		=	bsq

HEADER		=	./includes/

CC			=	gcc

CFLAGS		=	-Werror -Wall -Wextra -g -I $(HEADER)

SRCS		=	srcs/main.c \
					srcs/utils/ft_str_utils.c \
					srcs/utils/ft_str_utils2.c \
					srcs/utils/ft_square.c \
					srcs/utils/ft_files.c \
					srcs/utils/ft_int_utils.c \
					srcs/utils/ft_draw.c \

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean		:
				rm -rf $(OBJS)

fclean		:	clean
				rm $(NAME)

re			:	fclean all