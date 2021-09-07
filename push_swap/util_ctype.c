int	ft_isspace(char ch)
{
	return ((ch >= 9 && ch <= 13) || ch == ' ');
}

int	ft_isdigit(char ch)
{
	return (ch >= '0' && ch <= '9');
}

int	ft_sign(char ch)
{
	if (ch == '+')
		return (1);
	if (ch == '-')
		return (-1);
	return (0);
}