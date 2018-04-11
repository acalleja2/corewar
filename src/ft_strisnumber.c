#include "../libft/libft.h"

int			ft_strisnumber(char *str)
{
	size_t	i;
	size_t len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
