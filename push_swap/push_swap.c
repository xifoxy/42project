#include "push_swap.h"
#include <fcntl.h>
// int ac = 2;
// char *ag[] = {"", "-631 -670 363 984 495 100 -674 78 -276 309"};

void	save_test(int ac, char **ag)
{
	// int fd = open("sample", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	for(int i = 1; i < ac; ++i)
	{
		for(int j = 0; j < ag[i][j]; ++j)
		{
			write(3, &ag[i][j], 1);
		}
		write(3, "\n", 1);
	}
}

int		main(int ac, char **ag)
{
	t_stack	st_a;
	t_stack	st_b;
	t_stack	it;
	t_info	info;

	// int fd = open("sample", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// save_test(ac, ag);
	
	ft_memset((char *)&info, sizeof(t_info), 0);
	ft_memset((char *)&st_a, sizeof(t_stack), 0);
	ft_memset((char *)&st_b, sizeof(t_stack), 0);
	init(ac, ag, &st_a);
	info.a_sz = get_size(&st_a);
	if (check_sort(&st_a) == info.a_sz)
		return (0);
	if (info.a_sz > 3)
		run(&st_a, &st_b, it, info);
	else if(info.a_sz <= 3)
		samll_exception(&st_a, info.a_sz);
	while (st_a.iter_a)
	{
		printf("%d\n", st_a.iter_a->num);
		st_a.iter_a = st_a.iter_a->next;
	}
}
