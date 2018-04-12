#include "corewar.h"

/*
** FONCTION DE TEST
*/
void	print_args(t_args *args)
{
	printf("dump: %d\t", args->dump);
	printf("cycles: %d\t", args->cycles);
	printf("verbosity: %d\t", args->verbosity);
	printf("binary_ouput: %d\t", args->binary_output);
	printf("ncurses: %d\n", args->ncurses);
	printf("process1: %d\n", args->process1);
	printf("process1: %d\n", args->process2);
	printf("champ1: %s\n", args->champ1);
	printf("champ2: %s\n", args->champ2);
}

/*
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

/*
** Si arg est -v, verifie que l'arg suivant est un chiffre et le memorise
** dans arg => c'est le niveau de verbosite lors de l'affichage
** Si -v, mais pas bon argument, affiche usage et exit;
** Si pas -v, on retourne au parsing voir si c'est autre chose
** -v utilise des masques binaires definis dans corewar.h
*/
void		ft_v(int argc, char *argv[], int *i, t_args *args)
{
	int		nbr;

	if (args->binary_output != -1 || args->ncurses != -1 || *i + 1 >= argc)
		ft_error_parse();
	if (args->verbosity != -1)
		ft_error_parse();
	if (!ft_strisnumber(argv[*i + 1]))
		ft_error_parse();
	nbr = ft_atoi(argv[*i + 1]);
	args->verbosity = nbr;
	*i += 2;
}

/*
** Si arg est -b, deux possibilites. Soit on a pas de parametres, et donc b = 0
** soit le parametre -stealth complete b, et b = 1
** Sinon on fait rien, et on reprends le parsing
*/
void		ft_b(int argc, char *argv[], int *i, t_args *args)
{
	if (args->dump != -1 || args->cycles != -1 || args->verbosity != -1 ||
			args->ncurses != -1)
		ft_error_parse();
	if (args->binary_output != -1)
		ft_error_parse();
	if (*i + 1 < argc && !ft_strcmp(argv[*i + 1], "--stealth"))
	{
		args->binary_output = 1;
		*i += 2;
	}
	else
	{
		*i += 1;
		args->binary_output = 0;
	}
}

void		ft_parse_name(char *argv[], int *i, t_args *args)
{
	if (args->champ1 == NULL)
	{
		args->process1 = ft_atoi(argv[*i + 1]);
		args->champ1 = ft_strdup(argv[*i + 2]);
	}
	else 
	{
		args->process2 = ft_atoi(argv[*i + 1]);
		args->champ2 = ft_strdup(argv[*i + 2]);
	}
}

/*
** Si arg est -b, deux possibilites. Soit on a pas de parametres, et donc b = 0
** soit le parametre -stealth complete b, et b = 1
** Sinon on fait rien, et on reprends le parsing
*/
void		ft_n(int argc, char *argv[], int *i, t_args *args)
{
	if (*i + 2 < argc && ft_strisnumber(argv[*i + 1]))
	{
		ft_parse_name(argv, i, args);
		*i += 3;
		return ;
	}
	if (args->dump != -1 || args->cycles != -1 || args->verbosity != -1 ||
			args->binary_output != -1)
		ft_error_parse();
	if (args->binary_output != -1)
		ft_error_parse();
	if (*i + 1 < argc && !ft_strcmp(argv[*i + 1], "--stealth"))
	{
		args->ncurses = 1;
		*i += 2;
	}
	else
	{
		*i += 1;
		args->ncurses = 0;
	}
}

/*
** Recupere les arguments et les place dans t_args
** A chaque tour de boucle, verifie si arg est valide ou pas.
** Si l'arg est valide, le place dans la strucut t_arg.
** Si l'argument ne correspond a aucun argument valide, affiche l'usage et exit.
** On peut prendre les arguments dans n'import quel ordre tant que le format
** est valide.
*/
void		ft_parseargs(int argc, char *argv[], t_args *args)
{
	int		i;

	i = 1;
	if (argc < 2)
		ft_error_parse();
	//print_args(args);
	while (i < argc)
	{
		//printf("%s\n", argv[i]);
		if (!strcmp(argv[i], "-d"))
			ft_d(argc, argv, &i, args);
		else if (!strcmp(argv[i], "-s"))
			ft_s(argc, argv, &i, args);
		else if (!strcmp(argv[i], "-v"))
			ft_v(argc, argv, &i, args);
		else if (!strcmp(argv[i], "-b"))
			ft_b(argc, argv, &i, args);
		else if (!strcmp(argv[i], "-n"))
			ft_n(argc, argv, &i, args);
		else
			ft_error_parse();
	}
	//check_args(args);
	print_args(args);
}
