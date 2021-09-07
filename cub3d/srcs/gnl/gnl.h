/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:40:07 by sgang             #+#    #+#             */
/*   Updated: 2021/05/25 12:40:29 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# include <stdlib.h>
# include <unistd.h>

# define RET_SUCCESS	1
# define RET_ERROR	-1

int					ft_append(char **line, char ch, char token);
int					ft_gnl(int fd, char **line, int token);

#endif
