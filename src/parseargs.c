#include "corewar.h"

/*
**
** Verifie si le numero de process est valide. Si pas valide, lui attribue
**
*/
int			ft_valid_process(int candidate, t_args *args)
{
	int		i;

	printf("index candidat: %d, index courant: %d\n", candidate, args->index);
	i = 0;
	while (i < args->index)
	{
		printf("\targs->process[%d]: %d\n", i, args->process[i]);
		if (args->process[i] == candidate)
		{
			printf("\t\tl'index: %d est deja utilise\n", args->process[i]);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

/*
** Recupere les arguments et les place dans t_args
** A chaque tour de boucle, verifie si arg est valide ou pas.
** Si l'arg est valide, le place dans la strucut t_arg.
** Si l'argument ne correspond a aucun argument valide, affiche l'usage et exit
** On peut prendre les arguments dans n'import quel ordre tant aue le format
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
		else if (args->index < MAX_PLAYERS)
			ft_parse_name(argv, &i, args);
		else
			ft_error_parse();
	}
	//check_args(args);
	print_args(args);
}
