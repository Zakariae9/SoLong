SRCS = check_is_map_surrounded_by_walls.c checkmap1.c checkmap0.c main.c free.c join.c

SRCS_LIBFT = libft1/ft_isalpha.c libft1/ft_isdigit.c libft1/ft_isalnum.c libft1/ft_isascii.c libft1/ft_isprint.c\
libft1/ft_strlen.c libft1/ft_memset.c libft1/ft_bzero.c libft1/ft_memcpy.c libft1/ft_memmove.c libft1/ft_strlcpy.c libft1/ft_strlcat.c\
libft1/ft_toupper.c libft1/ft_tolower.c libft1/ft_strchr.c libft1/ft_strrchr.c libft1/ft_strncmp.c libft1/ft_memchr.c libft1/ft_memcmp.c\
libft1/ft_strnstr.c libft1/ft_atoi.c libft1/ft_calloc.c libft1/ft_strdup.c libft1/ft_substr.c libft1/ft_strjoin.c libft1/ft_strtrim.c libft1/ft_split.c\
libft1/ft_itoa.c libft1/ft_strmapi.c libft1/ft_striteri.c libft1/ft_putchar_fd.c libft1/ft_putstr_fd.c libft1/ft_putendl_fd.c libft1/ft_putnbr_fd.c

SRCS_GET = current_line/get_next_line.c 

NAME = so_long
FLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
OBJS = $(SRCS:.c=.o)
OBJS_LIBFT = $(SRCS_LIBFT:.c=.o)
OBJS_GET = $(SRCS_GET:.c=.o)

all:$(NAME)

$(NAME):$(OBJS) $(OBJS_LIBFT) $(SRCS_GET)
	cc $(FLAGS) $(OBJS) $(OBJS_LIBFT) $(SRCS_GET) -o $(NAME)

%.o:%.c
	cc $(FLAGS) -c $< -o $@

libft1/%.o:libft1/%.c
	cc $(FLAGS) -c $< -o $@

current_line/%.o:current_line/%.c
	cc $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_LIBFT)

fclean:clean
	$(RM) $(NAME)

re:fclean all

.PHONY:
	all clean fclean re