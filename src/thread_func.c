#include "philosofers.h"

void	ph_eat(t_phil *ph)
{
	pthread_mutex_lock(ph->lf);
	print_action(ph, FORK);
	pthread_mutex_lock(ph->rf);
	print_action(ph, FORK);
	ph->meal = time_now();
	ft_usleep(ph->ph_main->t2e);
	print_action(ph, EAT);
	ph->iter_num++;
	pthread_mutex_unlock(ph->lf);
	pthread_mutex_unlock(ph->rf);
}

void	ph_sleep_think(t_phil *ph)
{
	ft_usleep(ph->ph_main->t2s);
	print_action(ph, SLEEP);
	print_action(ph, THINK);
}

void	*thread_func(void *ph)
{
	t_phil	*p;

	p = (t_phil *)ph;
	while (!p->ph_main->ready)
		continue ;
	if (p->id)
		ft_usleep(p->ph_main->t2e * 0.9 + 1);
	while (!p->ph_main->over)
	{
		ph_eat(p);
		ph_sleep_think(p);
	}
	return (NULL);
}