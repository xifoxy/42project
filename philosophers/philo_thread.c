#include "philo.h"

void	*monitoring_sleep(void *arg)
{
	t_status	*st;
	t_nin		*nin;
	int			idx;

	st = (t_status *)arg;
	while (st->exit_flag == -1)
	{
		if (st->sleep_barrier_lock != st->even)
			continue ;
		idx = -1;
		pthread_mutex_lock(&st->safe_guard);
		st->table_time += *(st->info + TO_EAT);
		while (++idx < *(st->info + NUM_PHILO))
		{
			nin = st->gen + idx;
			if (!nin->sleep_checker || \
			nin->lstamp - st->table_time < *(st->info + TO_DIE))
				continue ;
			st->exit_flag = idx;
			break ;
		}
		st->sleep_barrier_lock = 0;
		pthread_mutex_unlock(&st->safe_guard);
	}
	return ((void *)0);
}

void	*monitoring_eat(void *arg)
{
	t_status	*st;
	t_nin		*nin;
	int			idx;

	st = (t_status *)arg;
	while (st->exit_flag == -1)
	{
		if (st->eat_barrier_lock != st->even)
			continue ;
		idx = -1;
		pthread_mutex_lock(&st->safe_guard);
		st->table_time += *(st->info + TO_EAT);
		if (!st->ate_even)
			st->ate_odd = st->odd;
		if (!st->ate_odd)
			st->ate_even = st->even;
		while (++idx < *(st->info + NUM_PHILO))
		{
			nin = st->gen + idx;
			if (nin->lstamp - st->table_time < *(st->info + TO_DIE))
				continue ;
			st->exit_flag = idx;
			break ;
		}
		st->eat_barrier_lock = 0;
		st->grab_barrier_lock = 0;
		pthread_mutex_unlock(&st->safe_guard);
	}
	return ((void *)0);
}

void	*simulator(void *arg)
{
	int			cycle;
	t_status	*st;
	t_nin		*gen;

	gen = (t_nin *)arg;
	st = gen->status;
	cycle = *(st->info + REPEAT);
	while (st->exit_flag == -1 && (st->repeat || cycle--))
	{
		if (gen->num % 2)
			while (!st->ate_even && st->exit_flag == -1)
				;
		else
			while (!st->ate_odd && st->exit_flag == -1)
				;
		grab_fork(gen, st);
		eating(gen, st);
		eating_manager(gen, st);
		drop_fork(gen, st);
		sleeping(gen, st);
		//thinking(gen, st);
	}
	return ((void *)0);
}

/*
		// if (!(gen->num % 2))
		// 	while (st->ate_even && st->exit_flag == -1)
		// 		;
		// else
		// 	while (st->ate_odd && st->exit_flag == -1)
		// 		;
*/
