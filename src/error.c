#include "philosofers.h"

void	error(char *c, t_philosofs *ph_main, t_phil *p, int flag)
{
	if (flag)
	{
		if (ph_main->death)
			free(ph_main->death);
		if (ph_main->fork)
			free(ph_main->fork);
		if (p)
			free(p);
	}
	ft_putstr_fd(c, 1);
	return (EXIT_FAILURE);
}