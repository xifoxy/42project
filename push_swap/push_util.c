#include "push_swap.h"

void	switch_stack(t_stack *st_a, t_stack *st_b)
{
	t_node	*temp;
	
	temp = st_a->iter_a;
	st_a->iter_a = st_a->iter_a->next;
	if (!st_a->iter_a)
	{
		st_a->iter_b = NULL;
	}
	if (!st_b->iter_a)
	{
		temp->next = NULL;
		st_b->iter_a = temp;
		st_b->iter_b = temp;
	}
	else
	{
		temp->next = st_b->iter_a;
		st_b->iter_a = temp;
	}
}
void	rotate_stack(t_stack *st, long long rotate, int st_size)
{
	t_node	*iter;
	t_node	*temp;

	if (rotate >= INF || !rotate || st_size == ft_abs(rotate))
		return ;
	if (rotate < 0)
		rotate = st_size + rotate;
	st->iter_b->next = st->iter_a;
	iter = st->iter_a;
	while (iter && --rotate)
		iter = iter->next;
	temp = iter->next;
	st->iter_a = temp;
	st->iter_b = iter;
	st->iter_b->next = NULL;
}

void	find_pos(t_move *mv, int a, int b, int flag)
{
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
	{
		if (flag && mv->tot < ft_max(ft_abs(a), ft_abs(b)))
			return ;
		mv->tot = ft_max(ft_abs(a), ft_abs(b));
		mv->s_rotate = b;
		if (ft_abs(a) < ft_abs(b))
			mv->s_rotate = a;
		mv->a_rotate = a - mv->s_rotate;
		mv->b_rotate = b - mv->s_rotate;
	}
	else
	{
		if (flag && mv->tot < (ft_abs(a - b)))
			return ;
		mv->tot = ft_abs(a) + ft_abs(b);
		mv->a_rotate = a;
		mv->b_rotate = b;
		mv->s_rotate = 0;
	}
}