#ifndef PHILOSOFERS
# define PHILOSOFERS

#include "pthread.h"
#include "stdlib.h"
#include "unistd.h"

typedef struct s_phil
{
	int id;
} t_phil;

typedef struct s_philosofs
{
	int	num;
	int	t2d;
	int	t2e;
	int	t2s;
	int	ready;
	int	ready;
	int	max_iter;
	int	check_meal;
	int	over;
	long int start;
	pthread_mutex_t	*death;
	pthread_mutex_t	*fork;
} t_philosofs;

int	ft_atoi(const char *nptr);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	error(char *c, t_philosofs *ph_main, t_phil *p, int flag);

#endif