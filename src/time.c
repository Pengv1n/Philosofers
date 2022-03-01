#include "philosofers.h"

long int	time_now(void)
{
	struct timeval now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

int	ft_usleep(long int time)
{
	long int	start;

	start = time_now();
	while ((time_now() - start) < time)
		usleep(150);
	return (1);
}

