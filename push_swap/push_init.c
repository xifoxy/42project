#include "push_swap.h"

int		get_size(t_stack *st)
{
	t_node	*it;
	int		ret;

	ret = 0;
	it = st->iter_a;
	while(it)
	{
		ret++;
		it = it->next;
	}
	return (ret);
}

void	newnode(int num, t_stack *st)
{
	if (st->iter_a == NULL)
	{
		st->iter_a = ft_calloc(1, sizeof(t_node), 0);
		st->iter_a->num = num;
		st->iter_b = st->iter_a;
	}
	else
	{
		st->iter_b->next = ft_calloc(1, sizeof(t_node), 0);
		st->iter_b = st->iter_b->next;
		st->iter_b->num = num;
	}
}

void	parse(int ac, char **ag, t_stack *st, int idx)
{
	char	*iter;
	int		sign;
	
	while (++idx < ac)
	{
		iter = *(ag + idx);
		while (*iter)
		{
			sign = 0;
			while (ft_isspace(*iter))
				++iter;
			sign = ft_sign(*iter);
			if (ft_sign(*iter))
				++iter;
			if (ft_isdigit(*iter))
				newnode(ft_atoi(&iter, sign), st);
			else if (sign)
				ft_exit("ERROR");
			if (!(*iter == '\0' || ft_isspace(*iter)))
				ft_exit("ERROR");
		}
	}
}

void	init(int ac, char **ag, t_stack *st)
{
	if (ac < 2)
		ft_exit("ERROR CHECK ARG");
	parse(ac, ag, st, 0);
	if (check_dup(st))
		ft_exit("ERROR");
}