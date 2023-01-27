/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhasni <eelhasni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:29:59 by eelhasni          #+#    #+#             */
/*   Updated: 2023/01/15 21:10:20 by eelhasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	while ((*needle && len > 0 && *haystack) \
	|| (needle && haystack && (len > 0 || (len == 0 && !*needle))))
	{
		i = 0;
		while ((haystack[i] == needle[i] && needle[i] && i < len))
			i++;
		if (--len && !needle[i])
			return ((char *)haystack);
		if (!*haystack++)
			return (NULL);
	}
	return (NULL);
}
