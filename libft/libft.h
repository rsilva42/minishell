/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva <rsilva@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:02:36 by rsilva            #+#    #+#             */
/*   Updated: 2018/03/07 14:50:30 by rsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

char				*ft_itoa(int n);
int					ft_intlen(int n);
void				ft_putnbr(int n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_putchar(char	c);
void				ft_strclr(char *s);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_datboi(int hecome);
char				*ft_strdup(char *src);
char				*ft_strnew(size_t size);
void				ft_swap(int *a, int *b);
void				ft_putstr(char const *s);
size_t				ft_strlen(const char *s);
int					ft_atoi(const char *str);
void				*ft_memalloc(size_t size);
void				ft_putendl(char const *s);
char				*ft_strtrim(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_bzero(void *b, size_t len);
void				ft_putchar_fd(char c, int fd);
int					ft_lstsize(t_list *begin_list);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strndup(char *src, size_t len);
void				ft_putstr_fd(char const *s, int fd);
size_t				ft_wordcount(char const *s, char c);
void				ft_putendl_fd(char const *s, int fd);
char				*ft_strcat(char *s1, const char *s2);
char				**ft_strsplit(char const *s, char c);
void				ft_lstadd(t_list **alst, t_list *new);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strcpy(char *dst, const char *src);
void				ft_striter(char *s, void (*f)(char *));
void				ft_lstaddend(t_list **alst, t_list *new);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
t_list				*ft_lstnew(void const *content, size_t content_size);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strnstr(const char *haystack, const char *needle,
														size_t len);

#endif
