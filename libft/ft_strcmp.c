/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhasni <eelhasni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:04:30 by eelhasni          #+#    #+#             */
/*   Updated: 2023/01/18 15:57:01 by eelhasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char c1;
	unsigned char c2;

	c1 = *(unsigned char *)s1++;
	c2 = *(unsigned char *)s2++;
	while (c1 == c2)
	{
		if (c1 == '\0')
			return (c1 - c2);
		c1 = *(unsigned char *)s1++;
		c2 = *(unsigned char *)s2++;
	}
	return (c1 - c2);
}
