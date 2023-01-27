/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhasni <eelhasni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:49:03 by eelhasni          #+#    #+#             */
/*   Updated: 2023/01/15 21:09:05 by eelhasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_striteri(char const *s, void (*f)(unsigned int, char *))
{
	int		i;

	i = -1;
	if (!s || !f)
		return (NULL);
	while (s[++i])
		f(i, (char *)&s[i]);
	return ((char *)s);
}
