NAME = libft.a

cc = gcc
flags = -Wall -Wextra -Werror
functions_c = 	libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c \
				libft/ft_free_list.c libft/ft_free_node.c libft/ft_free_tab.c \
				libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c \
				libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c \
				libft/ft_lstadd_back.c libft/ft_lstadd_front.c libft/ft_lstlast.c \
				libft/ft_lstlen.c libft/ft_lstnew.c libft/ft_memchr.c \
				libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c \
				libft/ft_memset.c libft/ft_putchar_fd.c libft/ft_putchar.c \
				libft/ft_putendl_fd.c libft/ft_putlst.c libft/ft_putnbr_fd.c \
				libft/ft_putnode.c libft/ft_putstr_fd.c libft/ft_putstr.c \
				libft/ft_puttab.c libft/ft_split.c libft/ft_strchr.c \
				libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlcat.c \
				libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strncmp.c \
				libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c \
				libft/ft_substr.c libft/ft_tabcpy.c libft/ft_tablen.c \
				libft/ft_tolower.c libft/ft_toupper.c \
				ft_printf/ft_hexlen.c ft_printf/ft_nbrlen.c ft_printf/ft_printf.c \
				ft_printf/ft_puthex_lowercase.c ft_printf/ft_puthex_uppercase.c \
				ft_printf/ft_putnbr.c ft_printf/ft_putptr.c ft_printf/ft_putuns.c \
				ft_printf/ft_s_c_d_p_conversion.c ft_printf/ft_unslen.c ft_printf/ft_x_xupper_u_conversion.c \
				get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \

headers = libft/libft.h ft_printf/ft_printf.h get_next_line/get_next_line.h
functions_o = *.o

all : $(NAME)

$(NAME) : $(functions_o)
	ar rc $(NAME) $^

$(functions_o) : $(functions_c) $(headers)
	$(CC) $(flags) -c $(functions_c) 

clean :
	rm $(NAME)
	rm *.o

fclean : clean
	rm -f $(NAME)

re : fclean
	make all

.PHONY : all clean fclean re
