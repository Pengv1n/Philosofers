#include "philosofers.h"

int	philosofers(t_philosofs *ph_main)
{
	t_phil  *phil;
	phil = (t_phil *) malloc(sizeof(t_phil) * ph_main->num);
	if (!phil || init_phil(ph_main, phil))
		return (EXIT_FAILURE);
}

int	init_mutex(t_philosofs *ph_main)
{
	int	i;

	i = -1;
	ph_main->death = 0;
	ph_main->fork = 0;
	ph_main->death = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
	if (!ph_main->death)
		return (error("Error: malloc death\n", ph_main, 0, 1));
	ph_main->fork = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t) * ph_main->num);
	if (!ph_main->fork)
		return (error("Error: malloc fork\n", ph_main, 0, 1));
	if (pthread_mutex_init(ph_main->death, NULL) == -1)
		return (error("Error: mutex init death\n", ph_main, 0 , 1));
	while (++i < ph_main->num)
		if (pthread_mutex_init(&ph_main->fork[i], NULL) == -1)
			return (error("Error: mutex init fork\n", ph_main, 0 ,1));
	return (0);
}

int init(t_philosofs *ph_main, char **argv)
{
    int mutex;

    mutex = -1;
    ph_main->num = ft_atoi(argv[1]);
    ph_main->t2d = ft_atoi(argv[2]);
    ph_main->t2e = ft_atoi(argv[3]);
    ph_main->t2s = ft_atoi(argv[4]);
    ph_main->ready = 0;
	ph_main->start = 0;
	ph_main->over = 0;
	ph_main->max_iter = -2;
	ph_main->check_meal = 0;
	if (argv[5])
	{
		ph_main->check_meal = 1;
		ph_main->max_iter = ft_atoi(argv[5]);
	}
	if (ph_main->num > 0)
		mutex = init_mutex(ph_main);
	return (mutex || ph_main->num < 1 || ph_main->t2s <= 0 ||
		ph_main->t2e <= 0 || ph_main->t2d <= 0 ||
		ph_main->max_iter == 0);
}

int main(int argc, char **argv)
{
    t_philosofs *ph_main;

    if ((argc != 5 && argc != 6) || init(ph_main, argv))
        return (error("Error: invalid argument\n", ph_main, 0 ,1));
	if ()
}