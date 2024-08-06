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
					srcs/utils/ft_stdin.c \

OBJS		=	$(SRCS:.c=.o)

RESET = \033[0m
PURPLE = \033[1;35m
GREEN = \033[1;32m
YELLOW = \033[1;33m

all: $(NAME)

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
clean:
	@echo "$(YELLOW)Deleting objects files...$(RESET)"
	@rm -rf $(OBJS)
	@echo "$(GREEN)Object files (based in 'src/') have been deleted !$(RESET)"

fclean: clean
	@echo "$(YELLOW)Deleting executable...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)The executable '$(NAME)' has been deleted !$(RESET)"

.PHONY: re fclean clean