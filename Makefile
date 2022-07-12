SRCS_DIR=
SRCS=	ft_initialize.c\
	ft_close_all.c\
	ft_hook.c\
	ft_lstnew.c\
	ft_lstadd_back.c\
	ft_lstclear.c\
	ft_lstlast.c\
	ft_lstiter.c\
	ft_lstsize.c\
	get_next_line_utils.c\
	get_next_line.c\
	ft_substr.c\
	ft_read_map.c\
	ft_split.c\
	ft_bresenham.c\
	ft_atoi.c\
	ft_iso_coord.c\

CFLAGS	= -Wall -Wextra -Werror

OBJS	= $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))

#B_DIR	=

#SRCS_B	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
#	  ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

#OBJS_B	= $(addprefix $(B_DIR), $(SRCS_B:.c=.o))

NAME	= fdf.a

HDR	= fdf.h

RM	= rm -f

all:	$(NAME)

$(NAME): $(OBJS) $(HDR)
	ar -crs $(NAME) $(OBJS)

%.o: %.c $(HDR_DIR)$(HDR)
	gcc $(CFLAGS) -c $< -o $@

#bonus: $(OBJS_B) $(HDR)
#	ar -crs $(NAME) $(OBJS_B)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus
