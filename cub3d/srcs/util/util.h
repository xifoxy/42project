/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:49:50 by sgang             #+#    #+#             */
/*   Updated: 2021/05/25 12:50:15 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <stdlib.h>
# include <unistd.h>
# include "../cub3d.h"

# define RET_SUCCESS	1
# define RET_ERROR		-1

void					ft_swap(void *a, void *b, int len);
int						ft_max(int a, int b);
int						ft_min(int a, int b);
int						ft_safe(int x, int y, int hei, int wid);
int						ft_isspace(char ch);
int						ft_isdigit(char ch);
void					ft_free(char **temp);
void					ft_memset(char *dest, int size, char ch);
void					ft_memcpy(char *dest, const char *src, int sz);
int						ft_exit(const char *err);
int						ft_atoi(char **str);
void					*ft_calloc(int number, int size, char ch);
int						ft_strnchr(const char *src, char ch, int sz);
int						ft_strlen(const char *str);
int						ft_strncmp(const char *s1, const char *s2, int size);

#endif
