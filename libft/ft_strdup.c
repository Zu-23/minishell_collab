/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhasni <eelhasni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:30:46 by eelhasni          #+#    #+#             */
/*   Updated: 2023/01/15 21:09:02 by eelhasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;

	new = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	return ((char *)ft_memcpy(new, s1, ft_strlen(s1) + 1));
}
