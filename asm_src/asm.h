/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:11:51 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/22 15:45:34 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "../libft/libft.h"
# include "op.h"
# include <fcntl.h>

typedef struct		s_op
{
	char			*name;
	int				param_num;
	int				param_type[3];
	int				opcode;
	int				cycle;
	char			*desc;
	int				ocp;
	int				nb_direct;
}					t_op;

extern t_op			g_op_tab[17];

typedef struct		s_label
{
	char			*name;
	struct s_label	*next;
}					t_label;

typedef struct		s_param
{
	char			*name;
	int				ret;
	int				nb_octet;
	int				value;
	struct s_param	*next;
}					t_param;

typedef struct		s_instru
{
	t_label			*lab;
	char			*opcode;
	t_param			*par;
	int				size;
	struct s_instru	*next;
	unsigned char	ocp;
}					t_instru;

void				add_n(char *buf, char **nm, char **str);
void				error_hd(int name, int desc, int i);
void				magic(int ret, header_t *head);
void				check_header2(char *str, int name, int desc, int *i);
void				init_head(header_t *head);
void				pars_nm_dc(char *str, int i, char *name);
void				line_reader2(char *line, t_label **lab, t_instru **ins);
int					is_indirect2(char *str, t_instru *beg, t_label *lab,
					t_instru *tmp);
int					is_direct2(char *str, t_instru *beg, t_label *lab,
					t_instru *tmp);
int					ret_dir_ind(char *str, int val);
int					ret_val(char *str, t_instru *ins, t_label *lab,
					t_instru *tmp);
void				add_rg_val(t_param *par);
char				*split_extend(char **tab, int len);
int					count_sep(char *str);
void				free_lab(t_label **lab);
void				free_param(t_param **par);
void				free_instru(t_instru **ins);
void				put_lab_value(t_instru *ins, t_label *lab);
void				rev_param(int nb_octet, int value, int fd);
void				print_param_fd(t_instru *ins, int fd);
void				add_value_param(t_param *par, int ret, t_instru *ins,
					t_instru *cur);
int					label_size(t_instru *ins, t_instru *cur, char *str,
					t_label *lab);
char				write_ocp(int ret, int i);
void				rev_instruc(int size, int fd);
int					count_size_tot(t_instru *tmp);
void				rev_magic(header_t *head, int fd);
void				add_empty_oct(int nb, int fd);
void				add_size(t_instru **tmp, int rank);
void				add_param_size(t_instru **tmp, int ret, int rank);
void				check_param(t_instru *ins, t_label *lab);
void				check_param2(t_instru *ins, t_label *lab, t_instru *tmp,
					int rank);
void				check_nb_param(t_instru *ins);
int					search_rank_op(char *str);
int					count_lst_lab(t_label *lab);
int					count_lst_ins(t_instru *ins);
int					count_lst_par(t_param *par);
void				check_header(char *str, int fd, header_t *head);
int					pars_name(char **str, header_t *head, int fd);
char				*pars_nm(char **str, int i, int fd);
int					pars_desc(char **str, header_t *head, int fd);
int					check_opcode(t_instru *ins);
void				del_lst_lab(t_label **lab);
void				print_lab(t_label *lab);
void				print_par(t_param *par);
void				print_ins(t_instru *ins);
void				str_replace(char *str, char c, char new_c);
int					label_chars(char c, char *str);
void				error_label(void);
void				error_header(void);
void				error_opcode(char *str);
void				error_param();
void				del_pos(char *str, int pos);
void				del_seq(char *str, int pos, int seq);
char				*ft_strn_dup(char *str, int n);
void				pars_label(char *str, t_label **lab);
void				free_tab(char **tab);
void				pars_opcode(char *str, t_instru **ins);
int					len_tab(char **tab);
void				pars_param(char *str, t_instru **ins);
void				create_lab_lst(t_label **lab, char *str);
void				create_param_lst(t_param **par, char *str);
void				create_instru_lst(t_instru **ins);
void				line_reader(int fd, t_label **lab, t_instru **ins,
					char *file);
int					all_digit(char *str);
int					is_reg(char *str);
int					is_direct(char *str, t_instru *beg, t_label *lab,
					t_instru *tmp);
int					is_indirect(char *str, t_instru *beg, t_label *lab,
					t_instru *tmp);
void				create_cor(char *file, t_instru *ins, header_t *head);
int					label_size2(t_instru *tmp, t_instru *cur, char *str,
					int *bol);

#endif
