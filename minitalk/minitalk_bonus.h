/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:31:15 by sgang             #+#    #+#             */
/*   Updated: 2021/08/03 20:43:12 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include "./util/util.h"

# define RET_TRUE		1
# define RET_FALSE		0

typedef struct s_info
{
	int				idx;
	int				bit;
	int				sz;
}	t_info;

typedef struct s_node
{
	unsigned char	*msg;
	int				idx;
	int				bit;
	int				sz;
	pid_t			pid;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	struct s_node	*iter_a;
	struct s_node	*iter_b;
}	t_list;

unsigned char	**arr_extend(unsigned char **src, int *sz);
t_node			*find_pid(t_list *list, pid_t pid);
t_node			*new_node(t_list *list, pid_t pid);
void			delete_node(t_node **node, t_list *list);
#endif
