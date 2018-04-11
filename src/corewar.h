#include "../libft/libft.h"
#include "op.h"
#include <fcntl.h>

#ifndef COREWAR_H
#define COREWAR_H

typedef struct	s_args {
	int			dump;
	int			cycles;
	int			verbosity;
	int			binary_output;
	int			ncurses;
	int			process1;
	int			process2;
	char		*champ1;
	char		*champ2;
} 				t_args;

typedef struct		s_process {
	int				process_nbr;
	char			*filename;
	int				fd;
	unsigned char	*registres[REG_NUMBER * REG_SIZE];
	unsigned char	pc;
	unsigned char	carry;
	int				alive;
}					t_process;

/*
typedef struct		s_cbuffer {
	unsigned char	*buffer;
	unsigned char	*head;
	unsigned char	*tail;
}
*/

typedef struct		s_proc {
	t_process		*process;
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
