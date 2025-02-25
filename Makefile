SRCS = check_is_map_surrounded_by_walls.c checkmap1.c checkmap0.c main.c 
NAME = so_long
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
OBJS = $(SRCS:.c=.o)

all:$(NAME)

$(NAME):$(OBJS)
	cc $(FLAGS) $(OBJS) -o $(NAME)

%.c:%.o
	cc $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:clean
	$(RM) $(NAME)

re:fclean all

.PHONY:
	all clean fclean re