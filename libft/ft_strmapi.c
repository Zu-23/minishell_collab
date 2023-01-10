/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhasni <eelhasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:48:50 by eelhasni          #+#    #+#             */
/*   Updated: 2022/07/05 17:32:31 by eelhasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	i = -1;
	if (s && f)
		str = ft_strdup(s);
	if (!s || !str || !f)
		return (NULL);
	while (s[++i])
		str[i] = f(i, s[i]);
	return (str);
}
