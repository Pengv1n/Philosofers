/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:14:01 by aregenia          #+#    #+#             */
/*   Updated: 2022/03/04 19:14:02 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOFERS_H
# define PHILOSOFERS_H

# include "pthread.h"
# include "stdlib.h"
# include "unistd.h"
# include "sys/time.h"
# include "stdio.h"

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"

typedef struct s_philosofs
{
	int				num;
	int				t2d;
	int				t2e;
	int				t2s;
	int				ready;
	int				max_iter;
	int				check_meal;
	int				over;
	long int		start;
	pthread_mutex_t	*death;
	pthread_mutex_t	*fork;
}	t_philosofs;

typedef struct s_phil
{
	int				id;
	int				dead;
	int				iter_num;
	long int		thread_start;
	long int		meal;
	pthread_t		life_tid;
	pthread_mutex_t	*lf;
	pthread_mutex_t	*rf;
	t_philosofs		*ph_main;
}	t_phil;

int			ft_atoi(const char *nptr);
int			error(char *c, t_philosofs *ph_main, t_phil *p, int flag);
int			init_thread(t_philosofs *ph_main, t_phil *phil);
int			ft_usleep(long int time);
long int	time_now(void);
void		print_action(t_phil *p, char *action);
void		*thread_func(void *ph);
void		check_thread(t_philosofs *ph_main, t_phil *phil);
void		free_all(t_philosofs *ph_main, t_phil *phil);

#endif
