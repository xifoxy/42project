#include "philo.h"

void	eating(t_nin *gen, t_status *st)
{
	if (st->exit_flag != -1)
		return ;
	st->eat_barrier_lock++;
	printf("gennum :%d [%d %d] %d\n", gen->num, st->ate_even, st->ate_odd, st->eat_barrier_lock);
	// if (*(st->info + NUM_PHILO) > 1)
	// {
		printf("%lld %d is eating\n", st->table_time, gen->num);
		gen->lstamp += *(st->info + TO_EAT);
	// }
	if (gen->num % 2)
		st->ate_even--;
	else
		st->ate_odd--;
	long long i = 1;
	while (st->eat_barrier_lock && st->exit_flag == -1)
	{
		// ++i;
		// if (i > 500000000)
		// 	puts("wtf3333333");
	}
}

void	sleeping(t_nin *gen, t_status *st)
{
	while (st->sleep_barrier_lock == st->even && st->exit_flag == -1)
	{
		puts("wtf1111111");
		
	}
	if (st->exit_flag != -1)
		return ;
	if (*(st->info + NUM_PHILO) > 1)
	{
		gen->sleep_checker = 1;
		printf("%lld %d is sleeping\n", st->table_time, gen->num);
		gen->lstamp += *(st->info + TO_SLEEP);
	}
	while (st->sleep_barrier_lock && st->exit_flag == -1)
		puts("wtf22222222");

}
