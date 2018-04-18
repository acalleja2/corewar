#include "corewar.h"

char		*kill1(void)
{
	char	*speak;

	speak = ft_strdup("echo \'ouch ouch no  please stop aaaaaaaaaaaa\' |"
			"espeak");
	return (speak);
}

char		*kill2(void)
{
	char	*speak;

	speak = ft_strdup("echo \'suka blyat\' | espeak");
	return (speak);
}

char		*kill3(void)
{
	char	*speak;

	speak = ft_strdup("echo \'ouch ouch no please stop aaaaaaaaaaaa\' |"
			"espeak");
	return (speak);
}

void		speak_kill(t_data *data)
{
	int		nbr;
	char	*speak;
	char	*(*jaipasenviedebosser[3])(void);

	jaipasenviedebosser[0] = kill1;
	jaipasenviedebosser[1] = kill2;
	jaipasenviedebosser[2] = kill3;
	nbr = rand() % 5;
	if (data->args->talk)
	{
		speak = jaipasenviedebosser[nbr]();
		system(speak);
		free(speak);
		speak = NULL;
	}
}
