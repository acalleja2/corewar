# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acalleja <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/20 20:26:17 by acalleja          #+#    #+#              #
#    Updated: 2018/04/20 20:38:24 by acalleja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = ../libft/libft.a
INC = asm.h

SRC = add_empty_oct.c\
	  add_param_size.c\
	  add_size.c\
	  add_value_param.c\
	  check_ins.c\
	  check_nb_param.c\
	  check_param.c\
	  count_lst.c\
	  count_sep.c\
	  count_size_tot.c\
	  create_cor.c\
	  create_instru_lst.c\
	  create_lab_lst.c\
	  create_param_lst.c\
	  del_pos.c\
	  error_syntax.c\
	  free_lst.c\
	  free_tab.c\
	  ft_strndup.c\
	  is_parm.c\
	  is_reg.c\
	  label_chars.c\
	  label_size.c\
	  len_tab.c\
	  line_reader.c\
	  main.c\
	  op.c\
	  pars_head.c\
	  pars_label.c\
	  pars_opcode.c\
	  pars_param.c\
	  print_parm_fd.c\
	  put_lab_value.c\
	  read_header.c\
	  rev_instruc.c\
	  rev_magic.c\
	  rev_param.c\
	  search_rank_op.c\
	  split_extend.c\
	  str_replace.c\
	  write_ocp.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(INC)
	make -C ../libft
	$(CC) $(CFLAGS) $(LIB) $(OBJ) -o $(NAME)

clean :
