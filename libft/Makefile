# project
NAME = libft.a

# compiler
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
AR = ar -rcs

# sources
SRC = 	src_str/str_utils.c \
	 	src_str/str_chr.c \
		src_str/str_cmp.c \
		src_str/str_join.c \
		src_str/str_iter.c \
		src_strs/split.c \
		src_strs/ft_is_in_tab.c \
		src_strs/strs_utils.c \
		src_write/printf.c \
		src_write/printf2.c \
		src_write/write.c \
		src_write/ft_putnbr_fd.c \
		src_is_type/ft_isalnum.c \
		src_is_type/ft_isalpha.c \
		src_is_type/ft_isascii.c \
		src_is_type/ft_isdigit.c \
		src_is_type/ft_isprint.c \
		src_is_type/ft_issign.c \
		src_is_type/ft_isspace.c \
		src_parsing_utils/ft_multisign.c \
		src_parsing_utils/ft_multiple_numbers.c \
		src_mem/memory.c \
		src_mem/alloc.c \
		src_convert/itoa.c \
		src_convert/atoi.c \
		src_convert/atof.c \
		src_file/get_next_line.c \
		src_file/get_next_line_utils.c \
		src_lst/lst_utils.c

OBJ =	$(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $^

%.o : %.c
	$(CC) -o $@ -c $^

# so:
# 	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
# 	gcc -nostartfiles -shared -o libft.so $(OBJ)

clean :
	rm -rf ${OBJ}

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean bonus re
