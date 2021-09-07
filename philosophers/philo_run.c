#include "philo.h"

void	run(t_status *st)
{
	int	idx;

	idx = -1;
	if (pthread_create(&(st->monitor_eat), NULL, monitoring_eat, (void *)st))
		return ;
	usleep(100);
	while (++idx < *(st->info + NUM_PHILO))
	{
		if (!pthread_create(&(st->gen[idx].th), NULL, \
		simulator, (void *)(st->gen + idx)))
		{
			usleep(100);
			st->cnt++;
			continue ;
		}
		st->exit_flag = RET_ERROR;
		printf("Error: Thread create failure");
		break ;
	}
	while (idx--)
		pthread_join((st->gen + idx)->th, NULL);
	printf("%d\n", st->exit_flag);
}

int	thread_init(t_status *st)
{
	int	idx;

	idx = -1;
	while (++idx < *(st->info + NUM_PHILO))
	{
		if (pthread_mutex_init(&(st->gen + idx)->foork, NULL))
			return (printf("Error: Mutex init failure"));
		(st->gen + idx)->lstamp = 0;
		(st->gen + idx)->status = st;
		(st->gen + idx)->num = idx;
	}
	if (pthread_mutex_init(&st->table, NULL))
		return (printf("Error: Mutex init failure"));
	if (pthread_mutex_init(&st->safe_guard, NULL))
		return (printf("Error: Mutex init failure"));
	if (pthread_mutex_init(&st->mic, NULL))
		return (printf("Error: Mutex init failure"));
	return (0);
}

int	init(int ac, char **ag, t_status *st)
{
	st = parser(ac, ag, st);
	if (!st)
		return (printf("Error: Check argument"));
	st->gen = malloc(sizeof(t_nin) * *(st->info + NUM_PHILO));
	if (!st->gen)
		return (printf("Error: Memory allocate failure"));
	st->exit_flag = -1;
	st->dp = (int *)malloc(*(st->info + NUM_PHILO) * sizeof(int));
	if (!st->dp)
		return (printf("Error: Memory allocate failure"));
	memset(st->dp, 0, sizeof(int) * *(st->info + NUM_PHILO));
	st->odd = *(st->info + NUM_PHILO) / 2;
	st->even = st->odd;
	if (*(st->info + NUM_PHILO) % 2)
		st->odd++;
	st->ate_even = st->even;
	if (!*(st->info + REPEAT))
		st->repeat = 1;
	return (thread_init(st));
}
