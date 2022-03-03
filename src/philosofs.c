#include "philosofers.h"

int	check_death(t_phil *ph)
{
	long int	now;

	pthread_mutex_lock(ph->ph_main->death);
	now = time_now() - ph->meal;
	if (now >= ph->ph_main->t2d)
	{
		pthread_mutex_unlock(ph->ph_main->death);
		print_action(ph, DIE);
		ph->ph_main->over = 1;
		ph->dead = 1;
		pthread_mutex_unlock(ph->lf);
		pthread_mutex_unlock(ph->rf);
		return (1);
	}
	pthread_mutex_unlock(ph->ph_main->death);
	return (0);
}

int check_meal(t_phil *ph, int i)
{
	if (ph->ph_main->check_meal && i == (ph->ph_main->num - 1)
		&& ph->iter_num == ph->ph_main->max_iter)
		return (ft_usleep(300));
	return (0);
}

void	check_thread(t_philosofs *ph_main, t_phil *phil)
{
	int i;

	while (!ph_main->ready)
		continue ;
	while (!ph_main->over)
	{
		i = -1;
		while (++i < ph_main->num)
			if (check_death(&phil[i]) || check_meal(&phil[i], i))
				ph_main->over = 1;
	}
	if (ph_main->check_meal && phil[ph_main->num - 1].iter_num == ph_main->max_iter)
	{
		ft_usleep(5 * ph_main->num);
		printf("Philosofers eated %d times\n", ph_main->max_iter);
		printf("No one philosofer don't die\n");
	}
}

int	init_thread(t_philosofs *ph_main, t_phil *phil)
{
	int	i;

	i = -1;
	while (++i < ph_main->num)
	{
		phil[i].rf = phil[(i + 1) % ph_main->num].lf;
		if (pthread_create(&phil[i].life_tid, NULL,
						   &thread_func, &phil[i]) == -1)
			return (error("Error: create thread\n", ph_main, phil, 1));
	}
	i = -1;
	ph_main->start = time_now();
	while (++i < ph_main->num)
	{
		phil[i].thread_start = ph_main->start;
		phil[i].meal = ph_main->start;
	}
	ph_main->ready = 1;
	return (0);
}
