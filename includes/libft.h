/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:07:17 by jeekpark          #+#    #+#             */
/*   Updated: 2023/07/24 16:03:59 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

# define BUFFER_SIZE 1024

typedef struct s_strtol
{
	const char		*s;
	unsigned long	acc;
	int				c;
	unsigned long	cutoff;
	int				neg;
	int				any;
	int				cutlim;
}	t_strtol;

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

void	ft_print_di(int nb, int *res);
void	ft_print_c(int c, int *res);
void	ft_print_s(char *str, int *res);
void	ft_print_x(unsigned int nbr, char x, int *res);
void	ft_print_p(void *addr, int *res);
void	ft_print_u(unsigned int nb, int *res);
int		ft_printf_err(const char *format, ...);

size_t	ft_gnl_strlen(const char *s);
char	*ft_gnl_strchr(char *s, int c);
size_t	ft_gnl_strchr_alt(const char *s, int c);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_gnl_substr(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);

int		ft_pow(int nb, int power);

long	ft_atol(const char *str);
long	ft_strtol(const char *nptr, char **endptr, int base);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isspace(int c);

int		ft_abs(int num);

#endif
