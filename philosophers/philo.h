#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# define RET_ERROR		-2
# define RET_SUCCESS	0
# define NUM_PHILO		0
# define TO_DIE			1
# define TO_EAT			2
# define TO_SLEEP		3
# define REPEAT			4

typedef struct s_status	t_status;
typedef struct s_nin
{
	pthread_t		th;
	pthread_mutex_t	foork;
	struct s_status	*status;
	long long		lstamp;
	int				sleep_checker;
	int				num;
}	t_nin;

struct s_status
{
	struct s_nin	*gen;
	int				*dp;
	int				info[5];
	pthread_t		monitor_eat;
	pthread_t		monitor_sleep;
	pthread_mutex_t	mic;
	pthread_mutex_t	safe_guard;
	pthread_mutex_t	table;
	long long		table_time;
	int				repeat;
	int				grab_monitor_lock;
	int				grab_barrier_lock;
	int				eat_barrier_lock;
	int				sleep_barrier_lock;
	int				barrier_flag;
	int				exit_flag;
	int				ate_even;
	int				ate_odd;
	int				even;
	int				odd;	// holsu
	int				cnt;
};

// philo_parser.c
t_status	*parser(int ac, char **ag, t_status *info);

// philo_util.c
long long	philo_gettime(void);

// philo_run.c
int		thread_init(t_status *st);
int		init(int ac, char **ag, t_status *st);
void	run(t_status *st);

// philo_thread.c
void	*monitoring_eat(void *arg);
void	*simulator(void *arg);

// philo_action_nontime.c
void	thinking(t_nin *gen, t_status *st);
void	grab_other_fork(t_nin *gen, t_status *st, int next);
void	grab_my_fork(t_nin *gen, t_status *st);
void	grab_fork(t_nin *gen, t_status *st);
void	drop_fork(t_nin *gen, t_status *st);

// philo_action_time.c
void	eating(t_nin *gen, t_status *st);
void	sleeping(t_nin *gen, t_status *st);

void	eating_manager(t_nin *gen, t_status *st);


#endif
