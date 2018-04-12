#include "corewar.h"

/*
** Verbosite
** si arg est -v, verifie que l'arg suivant est un chiffre et le memorise
** dans arg => c'est le niveau de verbosite lors de l'affichage
** si -v, mais pas bon argument, affiche usage et exit;
** si pas -v, on retourne au parsing voir si c'est autre chose
** -v doit avoir au moins un des bits 2, 3, 4 ou 5 sets, et aucun au dessus.
*/
void		ft_v(int argc, char *argv[], int *i, t_args *args)
{
	int		nbr;
	int		j;
	int		ok;

	j = 1;
	ok = FALSE;
	if (args->binary_output != -1 || args->ncurses != -1 || *i + 1 >= argc)
		ft_error_parse();
	if (args->verbosity != -1)
		ft_error_parse();
	if (!ft_strisnumber(argv[*i + 1]))
		ft_error_parse();
	nbr = ft_atoi(argv[*i + 1]);
	if (nbr < 30 && !(nbr & 1))
		while (j <= 4)
			if (nbr & (1 << j++))
				ok = TRUE;
	if (ok == FALSE)
		ft_error_parse();
	args->verbosity = nbr;
	*i += 2;
}

/*
** Nombre ce cycle au bout desquels on dump la memoire, PUIS EXIT
** Si arg est -d, verifie que l'arg suivant est un chiffre et le memorise
** dans arg => c'est le nbr de cycles au bout desquels on dump la memoire
** Si -d, mais pas bon argument, affiche usage et exit;
** Si pas -d, on retourne au parsing voir si c'est autre chose
*/
void		ft_d(int argc, char *argv[], int *i, t_args *args)
{
	if (args->binary_output != -1 || args->ncurses != -1 || *i + 1 >= argc)
		ft_error_parse();
	if (args->dump != -1)
		ft_error_parse();
	if (!ft_strisnumber(argv[*i + 1]))
		ft_error_parse();
	args->dump = ft_atoi(argv[*i + 1]);
	*i += 2;
	return ;
}

/*
** Nombre de cycle au bout desquels on dump la memoire, puis on recommence
** Fonctionne comme ft_d (au dessus)
*/

void		ft_s(int argc, char *argv[], int *i, t_args *args)
{
	if (args->binary_output != -1 || args->ncurses != -1 || *i + 1 >= argc)
		ft_error_parse();
	if (args->cycles != -1)
		ft_error_parse();
	if (!ft_strisnumber(argv[*i + 1]))
		ft_error_parse();
	args->cycles = ft_atoi(argv[*i + 1]);
	*i += 2;
}
