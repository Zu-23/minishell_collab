/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhasni <eelhasni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:46:12 by eelhasni          #+#    #+#             */
/*   Updated: 2023/01/16 19:16:15 by eelhasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	digit_in(long ln)
{
	size_t	dig;

	dig = 0;
	if (ln < 0 && !dig++)
		ln *= -1;
	while (++dig && ln > 9)
		ln /= 10;
	return (dig);
}

char	*ft_itoa(int n)
{
	long	ln;
	size_t	len;
	char	*str;

	ln = n;
	len = digit_in(ln);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	if (ln == 0)
		str[0] = 48;
	if (ln < 0)
	{
		str[0] = '-';
		ln *= -1;
	}
	while (ln > 0)
	{
		str[len--] = ln % 10 + 48;
		ln /= 10;
	}
	return (str);
}
