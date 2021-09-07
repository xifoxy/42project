#include "philo.h"

void	thinking(t_nin *gen, t_status *st)
{
	if (st->exit_flag != -1)
		return ;
	printf("%lld %d is thinking\n", gen->lstamp, gen->num);
}

void	grab_other_fork(t_nin *gen, t_status *st, int next)
{
	if (st->exit_flag != -1)
		return ;
	if (next == gen->num)
		return ;
	pthread_mutex_lock(&(st->gen + next)->foork);
	printf("%lld %d has taken a fork\n", st->table_time, gen->num);
	*(st->dp + next) = 1;
	st->grab_barrier_lock++;
	if (st->grab_barrier_lock == st->even)
		st->grab_monitor_lock = 1;
}

void	grab_my_fork(t_nin *gen, t_status *st)
{
	if (gen->status->exit_flag != -1)
		return ;
	pthread_mutex_lock(&gen->foork);
	*(st->dp + gen->num) = 1;
	printf("%lld %d has taken a fork\n", st->table_time, gen->num);
}

void	grab_fork(t_nin *gen, t_status *st)
{
	int	next;

	next = gen->num + 1;
	if (next == *(st->info + NUM_PHILO))
		next = 0;
	if (st->exit_flag != -1)
		return ;
	while (st->grab_barrier_lock == st->even)
		;
	pthread_mutex_lock(&st->table);
	if (*(st->dp + gen->num) || *(st->dp + next))
	{
		pthread_mutex_unlock(&st->table);
		grab_fork(gen, st);
		return ;
	}
	grab_my_fork(gen, st);
	grab_other_fork(gen, st, next);
	pthread_mutex_unlock(&st->table);
}

void	drop_fork(t_nin *gen, t_status *st)
{
	int	next;

	next = gen->num + 1;
	if (next == *(st->info + NUM_PHILO))
		next = 0;
	pthread_mutex_unlock(&gen->foork);
	*(st->dp + gen->num) = 0;
	if (gen->num == next)
		return ;
	pthread_mutex_unlock(&(st->gen + next)->foork);
	*(st->dp + next) = 0;
}
