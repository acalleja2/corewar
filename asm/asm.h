/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:11:51 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/12 20:38:41 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
#include "../libft/libft.h"
#include "../doc/op.h"
#include <fcntl.h>

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

extern t_op			op_tab[17];

typedef struct		s_label
{
	char			*name;
	struct s_label	*next;
}					t_label;

typedef struct		s_param
{
	char			*name;
	struct s_param	*next;
}					t_param;

typedef struct		s_instru
{
	t_label			*lab;
	char			*opcode;
	t_param			*par;
	struct s_instru	*next;
}					t_instru;

int					check_opcode(t_instru *ins);
void				del_lst_lab(t_label **lab);
void				print_lab(t_label *lab);
void				print_par(t_param *par);
void				print_ins(t_instru *ins);
void				str_replace(char *str, char c, char new_c);
int					label_chars(char c, char *str);
void				error_label(void);
void				error_opcode(char *str);
void				error_param(char *str);
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
void				line_reader(int fd, t_label **lab, t_instru **ins);

#endif
