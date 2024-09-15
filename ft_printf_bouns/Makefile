CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC_DIR = src
LIBFT_DIR = libft

SRC = create_obj.c execute_char.c execute_int.c execute_p.c execute_u.c ft_execute.c ft_printf.c hex.c utils.c \
	execute_hex.c execute_s.c
LIBFT_SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c \
	ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_unsigned_nbr.c

OBJ = $(SRC:%.c=$(SRC_DIR)/%.o)
LIBFT_OBJ = $(LIBFT_SRC:%.c=$(LIBFT_DIR)/%.o)

all : $(NAME)

$(OBJ) : $(SRC_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_OBJ) : $(LIBFT_DIR)/%.o : $(LIBFT_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(NAME)

$(NAME) : $(OBJ) $(LIBFT_OBJ)
	ar rcs $(NAME) $(OBJ) $(LIBFT_OBJ)

clean :
	rm -f $(SRC_DIR)/*.o $(LIBFT_DIR)/*.o

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
