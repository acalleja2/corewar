# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: florenzo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 19:32:11 by florenzo          #+#    #+#              #
#    Updated: 2017/11/10 19:06:40 by florenzo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# gcc est un alias de clang :/
CC = clang
CFLAGS = -Wall -Wextra -Werror -I. \
		 -g \
		 # -fsanitize=address

NAME = libft.a

MEMSRC = mem/ealloc.c \
		 mem/ft_bzero.c \
		 mem/ft_memalloc.c \
		 mem/ft_memccpy.c \
		 mem/ft_memchr.c \
		 mem/ft_memcmp.c \
		 mem/ft_memcpy.c \
		 mem/ft_memdel.c \
		 mem/ft_memmove.c \
		 mem/ft_memset.c
MEMOBJ = $(MEMSRC:%.c=%.o)

IFSSRC = ifs/ft_is_cinstr.c \
		 ifs/ft_is_toskip.c \
		 ifs/ft_isalnum.c \
		 ifs/ft_isalpha.c \
		 ifs/ft_isascii.c \
		 ifs/ft_isdigit.c \
		 ifs/ft_isprint.c \
		 ifs/ft_iswhitespace.c
IFSOBJ = $(IFSSRC:%.c=%.o)

STRSRC = str/ft_atoi.c \
		 str/ft_atoim.c \
		 str/ft_rstrrev.c \
		 str/ft_str_add.c \
		 str/ft_strcat.c \
		 str/ft_strchr.c \
		 str/ft_strclr.c \
		 str/ft_strcmp.c \
		 str/ft_strcpy.c \
		 str/ft_strdel.c \
		 str/ft_strdup.c \
		 str/ft_strequ.c \
		 str/ft_striter.c \
		 str/ft_striteri.c \
		 str/ft_strjoin.c \
		 str/ft_strlcat.c \
		 str/ft_strlen.c \
		 str/ft_strmap.c \
		 str/ft_strmapi.c \
		 str/ft_strncat.c \
		 str/ft_strncmp.c \
		 str/ft_strncpy.c \
		 str/ft_strnequ.c \
		 str/ft_strnew.c \
		 str/ft_strnstr.c \
		 str/ft_strrchr.c \
		 str/ft_strsplit.c \
		 str/ft_strstr.c \
		 str/ft_strsub.c \
		 str/ft_strtrim.c \
		 str/ft_vstrrev.c \
		 str/word_count.c \
		 str/get_word_ptr.c \
		 str/dup_word.c \
		 str/str_join_n.c
STROBJ = $(STRSRC:%.c=%.o)

PRINTFSRC = printf/adding.c \
			printf/asprintf.c \
			printf/buffer.c \
			printf/display.c \
			printf/fd.c \
			printf/get_stuff.c \
			printf/ifs.c \
			printf/int_processing.c \
			printf/out.c \
			printf/out_char.c \
			printf/out_int.c \
			printf/out_str.c \
			printf/out_uint.c \
			printf/out_voidptr.c \
			printf/out_wchar.c \
			printf/out_wstr.c \
			printf/parsing.c \
			printf/printf_core.c \
			printf/set_count.c \
			printf/stdout.c \
			printf/uint_processing.c \
			printf/uint_tools.c
PRINTFOBJ = $(PRINTFSRC:%.c=%.o)

GNLSRC = gnl/get_next_line.c
GNLOBJ = $(GNLSRC:%.c=%.o)

MISCSRC = misc/ft_putchar.c \
		  misc/ft_putstr.c \
		  misc/ft_tolower.c \
		  misc/ft_toupper.c \
		  misc/freen.c \
		  misc/errorf.c
MISCOBJ = $(MISCSRC:%.c=%.o)

OBJ = $(MEMOBJ) $(IFSOBJ) $(STROBJ) $(PRINTFOBJ) $(GNLOBJ) $(MISCOBJ)

all: $(NAME)

# changer le header recompile tout
$(OBJ): libft.h
$(PRINTFOBJ): printf.h
$(GNLOBJ): get_next_line.h

$(NAME): $(OBJ) libft.h
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
