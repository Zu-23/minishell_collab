/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhasni <eelhasni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:21:20 by eelhasni          #+#    #+#             */
/*   Updated: 2023/01/15 21:09:11 by eelhasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const size_t	len = ft_strlen(dst);

	if (len < dstsize)
		return (len + ft_strlcpy(dst + len, \
		src, dstsize - len));
	return (dstsize + ft_strlen(src));
}
