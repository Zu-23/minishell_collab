/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhasni <eelhasni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:45:25 by eelhasni          #+#    #+#             */
/*   Updated: 2023/01/16 03:41:24 by eelhasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	alloc_len(const char **s1, char const *set)
{
	size_t	len;

	len = 0;
	while (**s1 && ft_strchr(set, **s1))
		(*s1)++;
	len = ft_strlen(*s1);
	while ((int)len > 0 && (*s1)[(int)len - 1] \
	&& ft_strchr(set, (*s1)[(int)len - 1]))
		len--;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	const size_t	len = alloc_len(&s1, set);

	if (!s1)
		return (NULL);
	else if (!set)
		return ((char *)s1);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, len);
	str[len] = '\0';
	return (str);
}
