#include "push_swap.h"

int		check_sort(t_stack *st)
{
	t_node	*node;
	int		ret;

	ret = 1;
	node = st->iter_a;
	while (node)
	{
		if (node->next && node->num < node->next->num)
			ret++;
		else
			break;
		node = node->next;
	}
	return (ret);
}

int		check_dup(t_stack *st)
{
	t_node	*iter_a;
	t_node	*iter_b;

	iter_a = st->iter_a;
	while(iter_a)
	{
		iter_b = iter_a->next;
		while (iter_b)
		{
			if (iter_a->num == iter_b->num)
				return (1);
			iter_b = iter_b->next;
		}
		iter_a = iter_a->next;
	}
	return (0);
}