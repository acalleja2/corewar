#include "../libft/libft.h"
#include "op.h"
#include <fcntl.h>

#ifndef COREWAR_H
#define COREWAR_H

 #define FALSE 0
 #define TRUE 1

typedef struct	s_args {
	int			dump;
	int			cycles;
	int			verbosity;
	int			binary_output;
	int			ncurses;
	int			index;
	int			process_max;
	int			*process;
	char		**champions;
} 				t_args;

typedef struct		s_proc {
	int				process_nbr;
	char			*filename;
	int				fd;
	unsigned char	*registres[REG_NUMBER * REG_SIZE];
	unsigned char	pc;
	unsigned char	carry;
	int				alive;
	struct s_proc	*next;
}					t_proc;

void	ft_init_t_args(t_args *args);

void		ft_d(int argc, char *argv[], int *i, t_args *args);
void		ft_s(int argc, char *argv[], int *i, t_args *args);
void		ft_v(int argc, char *argv[], int *i, t_args *args);
void		ft_b(int argc, char *argv[], int *i, t_args *args);
void		ft_parse_name(char *argv[], int *i, t_args *args);
void		ft_n(int argc, char *argv[], int *i, t_args *args);
void		print_args(t_args *args);
void		ft_parseargs(int argc, char *argv[], t_args *args);

void		ft_error_parse();

void		ft_error_file(char *champ);

void		ft_corewar_engine(t_args *args);

int			ft_strisnumber(char *str);

#endif
