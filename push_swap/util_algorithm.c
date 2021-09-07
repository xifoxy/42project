int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	ft_swap(void *a, void *b, int len)
{
	char	*p;
	char	*q;
	char	temp;
	int		idx;

	p = a;
	q = b;
	idx = -1;
	while (++idx < len)
	{
		temp = *(p + idx);
		*(p + idx) = *(q + idx);
		*(q + idx) = temp;
	}
}