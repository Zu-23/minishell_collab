/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhasni <eelhasni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:45:50 by eelhasni          #+#    #+#             */
/*   Updated: 2023/01/15 21:08:54 by eelhasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	arr_size(const char *s, char delim)
{
	size_t	arr_n;

	arr_n = 0;
	while ((*s && *s != delim && ++arr_n) || *s)
		while (*s++ != delim && *s)
			continue ;
	return (arr_n);
}

static size_t	strstrlen(const char *s, char delim)
{
	size_t	len;

	len = 0;
	while (*s != delim && *s++)
			len++;
	return (len);
}

static void	*free_arr(char **arr, size_t n)
{
	while (n > 0)
		free(arr[--n]);
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	sz[4];

	if (s == NULL)
		return (NULL);
	*sz = 0;
	sz[2] = 0;
	sz[3] = arr_size(s, c);
	arr = malloc((sz[3] + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr[sz[3]] = NULL;
	while (sz[2] < sz[3])
	{
		while (s[*sz] == c)
			++*sz;
		sz[1] = strstrlen(s + *sz, c);
		arr[sz[2]] = ft_substr(s, *sz, sz[1]);
		if (!arr[sz[2]])
			return (free_arr(arr, sz[2]));
		sz[0] += sz[1];
		sz[2]++;
	}
	return (arr);
}
