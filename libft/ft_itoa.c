/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhasni <eelhasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:46:12 by eelhasni          #+#    #+#             */
/*   Updated: 2022/07/05 18:41:07 by eelhasni         ###   ########.fr       */
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
