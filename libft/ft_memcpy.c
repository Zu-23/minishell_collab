/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhasni <eelhasni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:44:49 by eelhasni          #+#    #+#             */
/*   Updated: 2023/01/15 21:08:20 by eelhasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*p_dst;

	p_dst = dst;
	if (!src && !dst)
		return (NULL);
	while (n-- > 0)
		(*(unsigned char *)dst++) = *((unsigned char *)src++);
	return (p_dst);
}
