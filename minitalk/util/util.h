/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:31:01 by sgang             #+#    #+#             */
/*   Updated: 2021/07/27 19:43:13 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <unistd.h>
# include <stdlib.h>

// algorithms
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		ft_abs(int a);
void	ft_swap(void *a, void *b, int len);

// stdlib
void	ft_exit(char *msg);
int		ft_atoi(char **num, int sign);
void	*ft_calloc(int number, int size, char ch);

// string
void	ft_memcpy(char *dest, char *src, int sz);
int		ft_strlen(char *str);
void	ft_memset(char *dest, int size, char ch);
int		ft_strcmp(char *s1, char *s2);

// print
void	ft_putnum(int num);
void	ft_putchar(unsigned char ch);
void	ft_puts(unsigned char *msg);

// ctype
int		ft_isspace(char ch);
int		ft_isdigit(char ch);
int		ft_isalpha(char ch);
int		ft_sign(char ch);

#endif