/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 18:25:44 by sgang             #+#    #+#             */
/*   Updated: 2021/03/29 21:39:17 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# define TRUE			1
# define FALSE			0
# define RET_ERROR		-1
# define RET_SUCCESS	1
# define SPACE			1
# define SPECIAL		2
# define PLUS			4
# define LEFT			8
# define ZEROPAD		16
# define L				32
# define LL				64
# define H				128
# define HH				256
# define SMALL			512
# define FLAG			" #+-0l h"
# define BASE			"c%sdiupxXn"
# define DIGIT			"0123456789abcdef0123456789ABCDEF"

typedef struct			s_info
{
	char				*format;
	int					type;
	int					len;
	int					flag;
	int					width;
	int					precision;
	int					base;
	int					point;
	int					check;
	char				*start;
	struct s_info		*next;
}						t_info;

int						(*g_func[128])(t_info *, va_list);
void					ft_function_init(void);
int						ft_print(t_info *lst, va_list args);
int						ft_printf(const char *fmt, ...);
int						ft_atoi(char **str);
void					ft_get_qualifier(t_info **lst, const char **iter);
void					ft_get_format(t_info **lst, char **iter, va_list args);
void					ft_get_info(t_info **lst, va_list args);
int						ft_parser(char *fmt, t_info **lst);
int						ft_free(t_info *lst, int status);
int						ft_calloc(int number, int size, void **ret, char ch);
void					ft_memcpy(void *dest, const void *src, int count);
int						ft_lstnew(char *fmt, int size, t_info **lst, int flag);
void					ft_memset(char *s, int sz, int ch);
int						ft_strlen(char *str);
int						ft_base(char ch);
int						ft_putstr(char **str, int len);
int						ft_max(int a, int b);
int						ft_isdigit(char ch);
int						ft_nlen(void *p, t_info *info);
char					ft_pad(t_info *info, void *num, int len);
void					ft_numcpy(char *dest, int sz, void *num, t_info *info);
void					ft_numcpy_unsigned(char *dest, int sz, void *num,
						t_info *info);
int						ft_type_pointer(t_info *info, va_list args);
int						ft_type_num(t_info *info, void *num);
int						ft_num_excep(t_info *info);
int						ft_type_number(t_info *info, va_list args);
int						ft_num_check(void *num, int signcheck);
int						ft_type_string(t_info *info, va_list args);
int						ft_type_char(t_info *info, va_list args);
int						ft_type_nonvariadic(t_info *info);
#endif
