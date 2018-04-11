/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:11:51 by acalleja          #+#    #+#             */
/*   Updated: 2018/04/11 19:34:07 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
#include "../libft/libft.h"
#include "../doc/op.h"

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
void				str_replace(char *str, char c, char new_c);
int					label_chars(char c, char *str);
void				error_syntax(void);
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
void				create_instru_lst(t_instru **ins, char *op, t_label **lab,
					t_param **par);
void				line_reader(int fd, t_label **lab, t_instru **ins);

#endif
