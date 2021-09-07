#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h>
#include <unistd.h>
#define MAX 20
#define INF 72340172838076673
#define INT_MAX	2147483647
#define INT_MIN	-2147483648


typedef struct		s_node
{
	int				num;
	struct s_node	*next;
}					t_node;

typedef struct		s_stack
{
	struct s_node	*iter_a;
	struct s_node	*iter_b;
}					t_stack;

typedef struct		s_move
{
	long long		num;
	long long		s_rotate;
	long long		a_rotate;
	long long		b_rotate;
	long long		tot;
}					t_move;

typedef struct		s_info
{
	struct s_move	mx;
	struct s_move	mn;
	struct s_move	mv;
	char			*push;
	int				a_sz;
	int				b_sz;
	int				i;
	int				j;
	int				push_cnt;
}					t_info;

// check
int		check_sort(t_stack *st);
int		check_dup(t_stack *st);

// init
void	init(int ac, char **ag, t_stack *st);
int		get_size(t_stack *st);

// stdlib
void	ft_exit(char *msg);
int		ft_atoi(char **num, int sign);
void	*ft_calloc(int number, int size, char ch);

// ctype
int		ft_sign(char ch);
int		ft_isspace(char ch);
int		ft_isdigit(char ch);

// string
void	ft_memcpy(char *dest, const char *src, int sz);
void	ft_memset(char *dest, int size, char ch);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);

// util_print
void	ft_puts(char *msg);

// util_algorithms
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		ft_abs(int a);
void	ft_swap(void *a, void *b, int len);

// push_print
void	put_cmd(char *msg, int cnt);
void	print_cmd(t_info info);

// push_exception
void	switch_stack(t_stack *st_a, t_stack *st_b);
void	samll_exception(t_stack *st_a, int st_size);

// push_run
void	run(t_stack *st_a, t_stack *st_b, t_stack it, t_info info);

// push_util
void	switch_stack(t_stack *st_a, t_stack *st_b);
void	rotate_stack(t_stack *st, long long rotate, int st_size);
void	find_pos(t_move *mv, int a, int b, int flag);

#endif