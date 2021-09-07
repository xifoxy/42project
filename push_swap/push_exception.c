#include "push_swap.h"

int		three_sort(t_stack *st, int st_size, int rotate, int swap)
{
	rotate_stack(st, rotate, st_size);
	if (check_sort(st) == st_size)
	{
		if (rotate < 0)
			put_cmd("rra", 1);
		if (rotate > 0)
			put_cmd("ra", 1);
		return (1);
	}
	ft_swap(&st->iter_a->num, &st->iter_a->next->num, sizeof(int));
	if (check_sort(st) == st_size)
	{
		if (rotate < 0)
			put_cmd("rra", 1);
		if (rotate > 0)
			put_cmd("ra", 1);
		put_cmd("sa", 1);
		return (1);
	}
	ft_swap(&st->iter_a->num, &st->iter_a->next->num, sizeof(int));
	rotate_stack(st, -rotate, st_size);
	return (0);
}

void	samll_exception(t_stack *st_a, int st_size)
{
	if (st_size == 2)
		put_cmd("sa", 1);
	else
	{
		if (three_sort(st_a, st_size, 1, 1))
			return ;
		if (three_sort(st_a, st_size, -1, 1))
			return ;
		if (three_sort(st_a, st_size, 0, 1))
			return ;
	}
}