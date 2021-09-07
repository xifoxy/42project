/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 02:14:44 by sgang             #+#    #+#             */
/*   Updated: 2020/10/20 23:42:45 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
int					ft_atoi(const char *string);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t number, size_t size);
int					ft_isalnum(const int ch);
int					ft_isalpha(const int ch);
int					ft_isascii(const int ch);
int					ft_isdigit(const int ch);
int					ft_isprint(const int ch);
char				*ft_itoa(int n);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list*l, void*(*f)(void *), void(*d)(void *));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				*ft_memccpy(void *d, const void *s, int c, size_t co);
void				*ft_memchr(const void *buffer, int c, size_t count);
int					ft_memcmp(const void *buf1, const void *buf2, size_t count);
void				*ft_memcpy(void *dest, const void *src, size_t count);
void				*ft_memmove(void *dest, const void *src, size_t count);
void				*ft_memset(void *dest, int c, size_t count);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *str, int c);
char				*ft_strdup(const char *string);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t				ft_strlen(const char *string);
int					ft_strncmp(const char *s1, const char *s2, size_t count);
char				*ft_strnstr(const char *b, const char *l, size_t len);
char				*ft_strrchr(const char *str, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(const int ch);
int					ft_toupper(const int ch);
#endif
