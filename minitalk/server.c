/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:30:33 by sgang             #+#    #+#             */
/*   Updated: 2021/07/27 19:34:06 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

int	bit_set(int signo, t_node *node)
{
	if (node->idx == node->sz)
		node->msg = *(arr_extend(&node->msg, &node->sz));
	if (SIGUSR1 == signo)
		*(node->msg + node->idx) |= (1 << node->bit);
	node->bit++;
	if (node->bit == 8)
	{
		if (!*(node->msg + node->idx))
			return (RET_TRUE);
		node->bit = 0;
		node->idx++;
	}
	return (RET_FALSE);
}

void	receive(int signo, siginfo_t *info, void *context)
{
	static t_list	list;
	t_node			*node;

	(void)context;
	if (!info->si_pid)
		return ;
	node = find_pid(&list, info->si_pid);
	if (!node)
		node = new_node(&list, info->si_pid);
	if (bit_set(signo, node))
	{
		*(node->msg + node->idx) = '\n';
		ft_puts(node->msg);
		delete_node(&node, &list);
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int ac, char **ag)
{
	const char			*msg = "Server PID : ";
	struct sigaction	sa;

	(void)ac;
	(void)ag;
	ft_puts((unsigned char *)msg);
	ft_putnum(getpid());
	ft_putchar('\n');
	sa.sa_flags |= SA_SIGINFO;
	sa.sa_sigaction = receive;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
