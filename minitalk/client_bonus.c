/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:28:30 by sgang             #+#    #+#             */
/*   Updated: 2021/08/03 20:43:42 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk_bonus.h"

int	g_p;

void	receive_checker(int i)
{
	(void)i;
	g_p = 1;
}

int	send_sig(char num, pid_t pid)
{
	long long	idx;
	int			sig;

	idx = 0;
	g_p = 0;
	sig = SIGUSR2;
	if (num)
		sig = SIGUSR1;
	if (kill(pid, sig) == -1)
		ft_exit("Error : Wrong PID.\n");
	while (!g_p)
	{
		++idx;
		if (idx == 500000000)
		{
			send_sig(num, pid);
			return (g_p);
		}
	}
	return (g_p);
}

int	devide_char(char ag, int depth, pid_t pid)
{
	int	ret;

	if (depth == 8)
		return (0);
	ret = send_sig(ag % 2, pid);
	ret += devide_char(ag >> 1, depth + 1, pid);
	return (ret);
}

int	traversal(char *msg, pid_t pid)
{
	const int	len = ft_strlen(msg);
	int			j;
	int			ret;

	j = -1;
	ret = 0;
	while (++j <= len)
		ret += devide_char(*(msg + j), 0, pid);
	return (ret);
}

int	main(int ac, char **ag)
{
	pid_t	pid;
	int		ret;

	if (ac != 3)
		ft_exit("Error : Check Parameter");
	signal(SIGUSR1, receive_checker);
	pid = ft_atoi(ag + 1, 0);
	ret = traversal(*(ag + 2), pid);
	ft_puts((unsigned char *)"Client PID : ");
	ft_putnum(getpid());
	ft_puts((unsigned char *)"\nSending Bytes : ");
	ft_putnum(ft_strlen(*(ag + 2)) + 1);
	ft_puts((unsigned char *)"\nReceive Bits : ");
	ft_putnum(ret);
}
