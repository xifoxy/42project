#include "push_swap.h"

void	sorting(t_stack *st_a, t_stack *st_b, t_stack it, t_info *info)
{
	while (info->push_cnt--)
	{
		it.iter_a = st_a->iter_a;
		info->i = -1;
		ft_memset((char *)&info->mv, sizeof(t_move), 1);
		while (it.iter_a)
		{
			++info->i;
			info->j = -1;
			it.iter_b = st_b->iter_a;
			ft_memset((char *)&info->mx, sizeof(t_move), 1);
			ft_memset((char *)&info->mn, sizeof(t_move), 1);
			info->mx.num= -info->mx.num;
			while (it.iter_b)
			{
				++info->j;
				if (it.iter_a->num > it.iter_b->num && info->mx.num < it.iter_b->num)
				{
					info->mx.num = it.iter_b->num;
					find_pos(&info->mx, info->i, info->j + 1, 0);
					find_pos(&info->mx, info->i, -(info->b_sz - info->j - 1), 1);
					find_pos(&info->mx, -(info->a_sz - info->i), info->j + 1, 1);
					find_pos(&info->mx, -(info->a_sz - info->i), -(info->b_sz - info->j - 1), 1);

				}
				if (it.iter_a->num < it.iter_b->num && info->mn.num > it.iter_b->num)
				{
					info->mn.num = it.iter_b->num;
					find_pos(&info->mn, info->i, info->j, 0);
					find_pos(&info->mn, info->i, -(info->b_sz - info->j), 1);
					find_pos(&info->mn, -(info->a_sz - info->i), info->j, 1);
					find_pos(&info->mn, -(info->a_sz - info->i), -(info->b_sz - info->j), 1);
				}
				it.iter_b = it.iter_b->next;
			}
			it.iter_a = it.iter_a->next;
			if (info->mn.tot <= info->mx.tot && info->mn.tot < info->mv.tot)
				info->mv = info->mn;
			else if (info->mx.tot < info->mv.tot)
				info->mv = info->mx;
		}
		rotate_stack(st_a, info->mv.s_rotate + info->mv.a_rotate, info->a_sz);
		rotate_stack(st_b, info->mv.s_rotate + info->mv.b_rotate, info->b_sz);
		if (!ft_strcmp(info->push, "pa"))
			ft_swap(&info->mv.a_rotate, &info->mv.b_rotate, sizeof(long long));
		print_cmd(*info);
		switch_stack(st_a, st_b);
		put_cmd(info->push, 1);
		info->b_sz++;
		info->a_sz--;
	}
}

void	rotate_sort(t_stack *st_a, t_info info)
{
	const int	get_rotate = check_sort(st_a);
	
	ft_swap((void *)&info.a_sz, (void *)&info.b_sz, sizeof(int));
	ft_memset((char *)&info.mv, sizeof(t_move), 0);
	if (ft_abs(get_rotate) < info.a_sz - ft_abs(get_rotate))
	{
		info.mv.a_rotate = get_rotate;
		rotate_stack(st_a, get_rotate, info.a_sz);
		print_cmd(info);	
	}
	else
	{
		info.mv.a_rotate = -(info.a_sz - ft_abs(get_rotate));
		rotate_stack(st_a, info.mv.a_rotate, info.a_sz);
		print_cmd(info);
	}
}

void	run(t_stack *st_a, t_stack *st_b, t_stack it, t_info info)
{
	info.push_cnt = info.a_sz / 2;
	info.push = "pb";
	sorting(st_a, st_b, it, &info);
	if (info.a_sz <= 3)
		samll_exception(st_a, info.a_sz);
	else
	{
		put_cmd(info.push, info.a_sz);
		while (info.a_sz-- && info.b_sz++)
			switch_stack(st_a, st_b);
		info.a_sz = 0;
	}
	info.push = "pa";
	info.push_cnt = info.b_sz;
	ft_swap((void *)&info.a_sz, (void *)&info.b_sz, sizeof(int));
	sorting(st_b, st_a, it, &info);
	rotate_sort(st_a, info);
}