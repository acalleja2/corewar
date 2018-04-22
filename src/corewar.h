/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florenzo <florenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 17:10:11 by florenzo          #+#    #+#             */
/*   Updated: 2018/04/22 10:44:16 by mschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "../libft/libft.h"
# include "op.h"
# include <fcntl.h>
# include <ncurses.h>
# define V_LIVES 1
# define V_CYCLES 2
# define V_OPERATIONS 4
# define V_DEATHS 8
# define V_PC 16
# define P1 
# define P2 0x3
# define P3 0xc0
# define OCP_P1
# define HEIGHT 	64
# define WIDTH 192
# define STARTX 10 
# define STARTY 10 

typedef struct		s_args
{
	char			**champions;
	int				dump;
	int				cycles;
	int				binary_output;
	int				ncurses;
	int				index;
	int				process_curr;
	int				*process;
	int				champ_number;
	int				talk;
	int				verbosity;
	int				rainbow;
}					t_args;

typedef struct		s_ch
{
	struct s_ch		*next;
	unsigned char	*code;
	char			*name;
	char			*comment;
	char			*filename;
	int				id;
	int				bytes;
	int				last_seen_alive;
	int				color_pair;
	int				nbr_process;
}					t_champion;

typedef struct		s_proc
{
	struct s_proc	*next;
	int				starting_pos;
	int				champion_id;
	int				live;
	int				time_to_wait;
	int				instruction_started;
	int				pc;
	int				carry;
	int				proc_color;
	int				registers[REG_NUMBER + 1];
	int				debug;
}					t_proc;

/*
** Le tableau map est la map sur laquelle se battent les champions
** Le tableau owner sert pour le visu, il se souvient de l'id du dernier
** process qui a ecrit sur la case de memoire correspondante
*/

typedef struct		s_mem
{
	// unsigned char	map[MEM_SIZE];
	// char			owner[MEM_SIZE];
	unsigned char	*map;
	char			*owner;
	int				cycle;
	int				cycle_to_die;
	int				since_last_check;
	int				checks_since_last_decrement;
}					t_mem;

typedef struct		s_header
{
	int				x;
	int				y;
	char			**header;
}					t_header;

typedef struct		s_data 	
{
	t_mem			*mem;
	t_args			*args;
	t_champion		*champs;
	t_proc			*procs;
	int				colors;
	int				speed;
	//t_header		*header;
	int				curr_cycle;
}					t_data;

extern void			(*const g_tab[17])(t_proc *process,
		t_data *data);
/*
** Toutes les instruction doivent commencer par le bloc suivant :
**     if (!process->instruction_started)
**     {
**         process->time_to_wait = <temps d'attente de l'instruction> - 2;
**         process->instruction_started = TRUE;
**         return ;
**     }
** Ce bloc sera s'executera la premiere fois que le process est appele, ca lui
** fera attendre n tours. Le -2 est la car on consomme un tour lorsqu'on lui 
** dit de repasser et un autre lorsqu'il execute reellement l'instruction.
**
** Si on n'a pas declenche le bloc precedent c'est que le process avait attendu
** le temps requis et on execute maintenant l'instruction a proprement parler.
** Apres ce bloc il faut imperativement rajouter la ligne suivante :
**     process->instruction_started = FALSE;
** Elle permet de "liberer" le process et lui permettra d'executer une autre
** instruction.
** A la fin du bloc il faut rajouter le bonus de verbosite :
**     if (data->args->verbosity & V_OPERATIONS)
**         ft_printf("P   %2i | <operation> %i %i %i\n",
**             process->champion_id, p1, p2, p3);
**
** A la fin il ne faut surtout pas oublier d'incrementer le pc :
**     increment_pc(data, process, offset);
** Ici l'offset est le nombre d'octets "consommes" par l'instruction a savoir,
** l'octet un octet pour l'opcode, un pour l'OCP et un nombre variable en
** fonction du type des parametres.
*/

void				ins_live(t_proc *process, t_data *data);
void				ins_ld(t_proc *process, t_data *data);
void				ins_st(t_proc *process, t_data *data);
void				ins_add(t_proc *process, t_data *data);
void				ins_sub(t_proc *process, t_data *data);
void				ins_and(t_proc *process, t_data *data);
void				ins_or(t_proc *process, t_data *data);
void				ins_xor(t_proc *process, t_data *data);
void				ins_zjmp(t_proc *process, t_data *data);
void				ins_ldi(t_proc *process, t_data *data);
void				ins_sti(t_proc *process, t_data *data);
void				ins_fork(t_proc *process, t_data *data);
void				ins_lld(t_proc *process, t_data *data);
void				ins_lldi(t_proc *process, t_data *data);
void				ins_lfork(t_proc *process, t_data *data);
void				ins_aff(t_proc *process, t_data *data);

/*
** ins_fork.c
*/
void				proc_cpy(t_proc *parent, t_proc *child);


/*
** init_t_args.c
*/

void				ft_init_t_args(t_args *args, t_mem *mem);

/*
** parse_text_output_mode.c
*/

void				ft_d(int argc, char *argv[], int *i, t_args *args);
void				ft_s(int argc, char *argv[], int *i, t_args *args);
void				ft_v(int argc, char *argv[], int *i, t_args *args);

/*
** parse_binary_mode.c
*/

void				ft_b(int argc, char *argv[], int *i, t_args *args);

/*
** parse_name.c
*/

void				ft_parse_name(char *argv[], int *i, t_args *args);
void				print_args(t_args *args);
void				ft_parseargs(int argc, char *argv[], t_args *args);
int					ft_valid_process(int candidate, t_args *args);

/*
** parse_n.c
*/

void				ft_n_name(char *argv[], int *i, t_args *args);
void				ft_n_curse(int argc, char *argv[], int *i, t_args *args);
void				ft_n(int argc, char *argv[], int *i, t_args *args);

/*
** parse_utilies.c
*/

void				print_args(t_args *args);
void				ft_error_parse(void);
void				ft_error_file(char *champ);
int					ft_strisnumber(char *str);

/*
** parse_rainbow.c
*/

void		ft_rainbow(char *argv[], int *i, t_args *args);

/*
** setup_champs.c
*/

void				setup_champions(t_data *data);
int					create_champ_list(t_data *data);

/*
** champion_initialization.c
*/

t_champion			*init_champion(int id, char *filename);
int					get_champ_data(t_champion *new, char *filename);

/*
** champ_list_tools.c
*/

void				champ_list_append(t_data *data, t_champion *new);
void				ft_print_champ_list(t_champion *champ);
int					champ_list_len(t_champion **list);
void				champ_list_free(t_champion **list);
t_champion			*get_champion_by_id(t_champion *champs, int id);

/*
** get_stuff.c
*/

int					error_reading(int readres, int expected, char *filename);
int					get_magic_number(int fd, t_champion *new, char *filename);
int					get_program_name(int fd, t_champion *new, char *filename);
int					no_null_byte(int fd, t_champion *new, char *filename);
int					get_byte_count(int fd, t_champion *new, char *filename);
int					get_program_desc(int fd, t_champion *new, char *filename);
int					get_champ_code(int fd, t_champion *new, char *filename);

/*
** mem_load.c
*/

void				mem_load(t_mem *mem, t_champion *current, int starting_pos);
void				add_process(t_data *data, t_champion *current, 
		int starting_pos);
void				load_champs_and_setup_processes(t_data *data);

/*
** mem_tools.c
*/

void				mem_setup_byte(t_mem *mem, unsigned char const byte, 
		int const pos, int const id);
void				mem_set_byte(t_data *data, t_proc *process, int offset, 
		unsigned char value);
void				print_mem(t_mem *mem);
unsigned char		mem_get_byte(t_data *data, t_proc *process, int pos);
int					mem_get_int(t_data *data, t_proc *process, int offset);
int					mem_get_short_int(t_data *data, t_proc *process, 
		int offset);
void				mem_set_int(t_data *data, t_proc *process, int offset, 
		int value);

/*
** proc_list_tools.c
*/

t_proc				*proc_new(int id, int starting_pos);
void				proc_list_add(t_data *data, t_proc *new);
void				print_proc_list(t_data *data);
void				proc_list_free(t_proc *current);

/*
** free_args.c
*/

void				ft_free_t_args(t_args *args);

/*
** vm_loop.c
*/

void				vm_loop(t_data *data);
void				exec_cycle(t_data *data);
void				print_cycle_start(t_data *data);
void				print_cycle_end(t_data *data);

/*
** parse_talk.c
*/

void				ft_t(char *argv[], int *i, t_args *args);

/*
** check_alive.c
*/

int					mem_check_alive(t_data *data);
int					count_all_lives(t_data *data);
void				clean_dead_processes(t_data *data);

/*
** print_winner.c
*/

void				print_winner(t_data *data, WINDOW *map);

/*
** switch_instruction.c
*/

void				switch_instruction(t_proc *process, 
		unsigned char instruction, t_data *data);

/*
** ncurses_tools.c
*/

void				print_map(WINDOW *win, int height, int width, t_data *data);
void				destroy_win(WINDOW *local_win);
void				clear_win(WINDOW *win, int height, int width);
WINDOW				*create_newwin(int height, int width, int starty, 
		int startx);

/*
** ncurse_colors.c
*/
int					check_process_colors(WINDOW *win, t_data *data);;
int					init_colors(t_data *data);
void				print_map_colors(WINDOW *win, int height, int width, 
		t_data *data);
int					find_colors(t_data *data, int id);
void				champ_color_pair(int *colors, t_data *data);

/*
** ncurses_tools2.c
*/

int					init_colors(t_data *data);
void				print_map_colors(WINDOW *win, int height, int width, 
		t_data *data);

void				init_main_window(void);
void				print_usage(int rows, int cols);
void				refresh_sleep(int sleep_time);
void				ncurses_winner(char	*speak, t_data *data, WINDOW *map);
void				wrefresh_sleep(WINDOW *win, int sleep_time);

/*
** ncurses_tools.c
*/

int					ncurses_main_loop(WINDOW *map, t_data *data);
void				end_ncurses(WINDOW *map);
WINDOW				*init_ncurse(t_data *data);
void				print_map_colors(WINDOW *win, int height, int width, 
		t_data *data);

/*
** ncurses_tools3.c
*/
void				print_map_colors(WINDOW *win, int height, int width, 
		t_data *data);

/*
** ncurses_tools4.c
*/
void				reinit_process_by_champion(t_data *data);
void				count_process_by_champion(t_data *data);
void				ncurse_pause(WINDOW *map, int *keep_going);
WINDOW				*init_ncurse(t_data *data);

/*
** ncurses_tools5.c
*/

void		change_speed(WINDOW *map, t_data *data, int ch);
void		init_header(t_data *data);
char		**generate_header(void);
void		put_header(int x_top_left, int y_top_left, t_data *d);

/*
** ocp_getters.c
*/

int					ocp_get_param1(t_data *data, t_proc *process, int offset, 
		int *var);
int					ocp_get_param2(t_data *data, t_proc *process, int offset, 
		int *var);
int					ocp_get_param3(t_data *data, t_proc *process, int offset, 
		int *var);
int					ocp_get_param1_ind(t_data *data, t_proc *process, 
		int offset, int *var);
int					ocp_get_param2_ind(t_data *data, t_proc *process, 
		int offset, int *var);
int					ocp_get_param3_ind(t_data *data, t_proc *process, 
		int offset, int *var);

/*
** process_parameters.c
*/

int					get_ocp_2_indirect_params(t_data *data, t_proc *process, int *p1, int *p2);
int					get_ocp_2_direct_params(t_data *data, t_proc *process, int *p1, int *p2);
int					get_ocp_3_indirect_params(t_data *data, t_proc *process, int *p1, int *p2, ...);
int					get_ocp_3_direct_params(t_data *data, t_proc *process, int *p1, int *p2, ...);
int					get_nth_register_value(t_proc *process, int n);
void				set_nth_register_value(t_proc *process, int n, int value);

/*
** ocp_ifs.c
*/

int					is_first_param_register(t_data *data, t_proc *process);
int					is_second_param_register(t_data *data, t_proc *process);

/*
** increment_pc.c
*/

void				increment_pc(t_data *data, t_proc *process, int offset);

/*
** stupid.c
*/
void				speak_kill(t_data *data);

#endif
