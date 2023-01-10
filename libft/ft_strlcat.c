/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhasni <eelhasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:21:20 by eelhasni          #+#    #+#             */
/*   Updated: 2022/07/05 17:32:26 by eelhasni         ###   ########.fr       */
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
