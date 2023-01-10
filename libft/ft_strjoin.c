/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhasni <eelhasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:45:12 by eelhasni          #+#    #+#             */
/*   Updated: 2022/07/05 17:32:18 by eelhasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len[2];

	if (!s1 || !s2)
		return (NULL);
	len[0] = ft_strlen(s1);
	len[1] = ft_strlen(s2);
	str = malloc((len[0] + len[1] + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, len[0]);
	ft_memcpy(str + len[0], s2, len[1]);
	str[len[0] + len[1]] = '\0';
	return (str);
}
