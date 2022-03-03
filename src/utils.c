#include "philosofers.h"

int	error(char *str, t_philosofs *ph_main, t_phil *p, int flag)
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
	printf("%s", str);
	return (EXIT_FAILURE);
}

void	print_action(t_phil *p, char *action)
{
	pthread_mutex_lock(p->ph_main->death);
	if (p->ph_main->over)
	{
		pthread_mutex_unlock(p->ph_main->death);
		return ;
	}
	printf("%ldms %d %s\n", time_now() - p->thread_start,
		   p->id + 1, action);
	pthread_mutex_unlock(p->ph_main->death);
}
void	free_all(t_philosofs *ph_main, t_phil * phil)
{
	int	i;

	i = -1;
	while (++i < ph_main->num)
		pthread_join(phil[i].life_tid, (void *)&phil[i]);
	pthread_mutex_destroy(ph_main->death);
	pthread_mutex_destroy(ph_main->fork);
	free(ph_main->death);
	free(ph_main->fork);
	free(phil);
}