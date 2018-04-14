/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 17:10:11 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/14 17:10:11 by florenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "../libft/libft.h"
# include "op.h"
# include <fcntl.h>

typedef struct	s_args
{
	char		**champions;
	int			dump;
	int			cycles;
	int			verbosity;
	int			binary_output;
	int			ncurses;
	int			index;
	int			process_curr;
	int			*process;
	int			champ_number;
	int			talk;
}				t_args;

typedef struct	s_champion
{
	struct s_champion	*next;
	unsigned char		*code;
	char				*name;
	char				*comment;
	char				*filename;
	int					id;
	int					bytes;
	int					last_seen_alive;
}				t_champion;

typedef struct	s_proc
{
	struct s_proc	*next;
	int				starting_pos;
	int				champion_id;
	int				live;
	int				time_to_wait;
	unsigned char	registers[REG_NUMBER * REG_SIZE];
	unsigned char	pc;
	unsigned char	carry;
}				t_proc;

/*
** Le tableau map est la map sur laquelle se battent les champions
** Le tableau owner sert pour le visu, il se souvient de l'id du dernier
** process qui a ecrit sur la case de memoire correspondante
*/

typedef struct	s_mem
{
	unsigned char	map[MEM_SIZE];
	char			owner[MEM_SIZE];
	int				cycle;
	int				cycle_to_die;
	int				since_last_check;
	int				checks_since_last_decrement;
}				t_mem;

typedef struct	s_data 	
{
	t_mem		*mem;
	t_args		*args;
	t_champion	*champs;
	t_proc		*procs;
}				t_data;

extern void		(*const g_tab[17])(t_proc *process,
		t_data *data);

void			ins_live(t_proc *process, t_data *data);
void			ins_ld(t_proc *process, t_data *data);
void			ins_st(t_proc *process, t_data *data);
void			ins_add(t_proc *process, t_data *data);
void			ins_sub(t_proc *process, t_data *data);
void			ins_and(t_proc *process, t_data *data);
void			ins_or(t_proc *process, t_data *data);
void			ins_xor(t_proc *process, t_data *data);
void			ins_zjmp(t_proc *process, t_data *data);
void			ins_ldi(t_proc *process, t_data *data);
void			ins_sti(t_proc *process, t_data *data);
void			ins_fork(t_proc *process, t_data *data);
void			ins_lld(t_proc *process, t_data *data);
void			ins_lldi(t_proc *process, t_data *data);
void			ins_lfork(t_proc *process, t_data *data);
void			ins_aff(t_proc *process, t_data *data);

/*
** init_t_args.c
*/

void			ft_init_t_args(t_args *args, t_mem *mem);

/*
** parse_text_output_mode.c
*/

void			ft_d(int argc, char *argv[], int *i, t_args *args);
void			ft_s(int argc, char *argv[], int *i, t_args *args);
void			ft_v(int argc, char *argv[], int *i, t_args *args);

/*
** parse_binary_mode.c
*/

void			ft_b(int argc, char *argv[], int *i, t_args *args);

/*
** parse_name.c
*/

void			ft_parse_name(char *argv[], int *i, t_args *args);
void			print_args(t_args *args);
void			ft_parseargs(int argc, char *argv[], t_args *args);
int				ft_valid_process(int candidate, t_args *args);

/*
** parse_n.c
*/

void			ft_n_name(char *argv[], int *i, t_args *args);
void			ft_n_curse(int argc, char *argv[], int *i, t_args *args);
void			ft_n(int argc, char *argv[], int *i, t_args *args);

/*
** parse_utilies.c
*/
void			print_args(t_args *args);
void			ft_error_parse();
void			ft_error_file(char *champ);
int				ft_strisnumber(char *str);

/*
** setup_champs.c
*/
void			setup_champions(t_data *data);
int				create_champ_list(t_data *data);

/*
** champion_initialization.c
*/
t_champion		*init_champion(int id, char *filename);
int				get_champ_data(t_champion *new, char *filename);

/*
** champ_list_tools.c
*/
void			champ_list_append(t_data *data, t_champion *new);
void			ft_print_champ_list(t_champion *champ);
int				champ_list_len(t_champion **list);
void			champ_list_free(t_champion **list);
t_champion		*get_champion_by_id(t_champion *champs, int id);

/*
** get_stuff.c
*/
int				error_reading(int readres, int expected, char *filename);
int				get_magic_number(int fd, t_champion *new, char *filename);
int				get_program_name(int fd, t_champion *new, char *filename);
int				no_null_byte(int fd, t_champion *new, char *filename);
int				get_byte_count(int fd, t_champion *new, char *filename);
int				get_program_desc(int fd, t_champion *new, char *filename);
int				get_champ_code(int fd, t_champion *new, char *filename);

/*
** mem_load.c
*/

void			mem_load(t_mem *mem, t_champion *current, int starting_pos);
void			add_process(t_data *data, t_champion *current, int starting_pos);
void			load_champs_and_setup_processes(t_data *data);

/*
** mem_tools.c
*/

void			mem_set_byte(t_mem *mem, unsigned char const byte, int const pos, int const id);
void			print_mem(t_mem *mem);
unsigned char	mem_get_byte(t_data *data, t_proc *process, int pos);

/*
** proc_list_tools.c
*/

t_proc			*proc_new(int id, int starting_pos);
void			proc_list_add(t_data *data, t_proc *new);
void			print_proc_list(t_data *data);
void			proc_list_free(t_proc *current);

/*
** free_args.c
*/

void	ft_free_t_args(t_args *args);

/*
** vm_loop.c
*/

void			vm_loop(t_data *data);
void			exec_cycle(t_data *data);

/*
** parse_talk.c
*/

void			ft_t(char *argv[], int *i, t_args *args);

/*
** check_alive.c
*/

int				mem_check_alive(t_data *data);
int				count_all_lives(t_data *data);
void			clean_dead_processes(t_data *data);

/*
** print_winner.c
*/

void			print_winner(t_data *data);

/*
** switch_instruction.c
*/

void			switch_instruction(t_proc *process, unsigned char instruction, t_data *data);

#endif
