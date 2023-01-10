/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhasni <eelhasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:29:59 by eelhasni          #+#    #+#             */
/*   Updated: 2022/07/05 17:32:38 by eelhasni         ###   ########.fr       */
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
