C = clang

NAME = pushswap.a

FLAGS = -Wall -Wextra -Werror

FTPRINTF = ft_printf

DIR_S = src

DIR_O = temporary

MAIN = main.c

SOURCES = 	ft_push_swap.c \
			ft_algoritm.c \
			ft_print_stack.c \
			ft_order_three.c \
			ft_move_top.c \
			ft_move_bootm.c \
			ft_max_three.c \
			ft_min_three.c \
			ft_order_end.c \
			ft_best_move_b.c \
			ft_sa.c \
			ft_sb.c \
			ft_ss.c \
			ft_pa.c \
			ft_pb.c \
			ft_ra.c \
			ft_rb.c \
			ft_rr.c \
			ft_rra.c \
			ft_rrb.c \
			ft_rrr.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	#@make -C $(FTPRINTF)
	@cp $(FTPRINTF)/libftprintf.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	@$(CC) $(FLAGS) -o $@ -c $<

norme:
	norminette ./libft/
	@echo
	norminette ./$(DIR_S)/

test:
	make re
	$(CC) $(NAME) $(MAIN)
	#./a.out 92 97 33 93 47 26 31 38 89 51 64 37 63
	#./a.out 2 1 3 6 5 8
	./a.out 11 81 22 55 29 71 34 10 75 39 79

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	#@make clean -C $(FTPRINTF)

fclean: clean
	@rm -f $(NAME)
	#@make fclean -C $(FTPRINTF)

re: fclean all