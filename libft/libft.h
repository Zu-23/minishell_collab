/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhasni <eelhasni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:07:23 by eelhasni          #+#    #+#             */
/*   Updated: 2023/01/17 18:31:56 by eelhasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

/*
** Macros :
*/

# define FT_ERR		-1
# define FT_SUCC	0
# define FT_TRUE	1
# define FT_FALSE	0
# define FT_INT_MAX 2147483647
# define FT_INT_MIN -2147483648

/*
** Data types :
*/

typedef unsigned char		t_bool;
typedef unsigned int		t_uint;
typedef unsigned char		t_uchar;
typedef unsigned char		t_uint8;
typedef unsigned short int	t_uint16;
typedef unsigned int		t_uint32;
typedef unsigned long int	t_uint64;

/*
** String operations	:
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_striteri(char const *s, void (*f)(unsigned int, char *));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split(char const *s, char c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

/*
** Memory operations :
*/

void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);

/*
** Conversion Functions	:
*/

int		ft_atoi(const char *str);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_itoa(int n);

/*
** Test Functions	:
*/

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isdigit(int c);

/*
** I/O operations	:
*/

void	ft_putnbr(int n);
void	ft_putstr(char *s);
void	ft_putchar(char c);
void	ft_putendl(char *s);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);


#endif
