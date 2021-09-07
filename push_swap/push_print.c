#include "push_swap.h"

void	put_cmd(char *msg, int cnt)
{
	while (cnt < 0)
	{
		++cnt;
		ft_puts(msg);
	}
	while (cnt > 0)
	{
		--cnt;
		ft_puts(msg);
	}
}

void	print_cmd(t_info info)
{
	if (info.mv.tot == INF)
		return ;
	if (info.mv.s_rotate > 0)
		put_cmd("rr", info.mv.s_rotate);
	else
		put_cmd("rrr", info.mv.s_rotate);
	if (info.mv.a_rotate > 0)
		put_cmd("ra", info.mv.a_rotate);
	else
		put_cmd("rra", info.mv.a_rotate);
	if (info.mv.b_rotate > 0)
		put_cmd("rb", info.mv.b_rotate);
	else
		put_cmd("rrb", info.mv.b_rotate);
}