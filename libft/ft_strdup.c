/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhasni <eelhasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:30:46 by eelhasni          #+#    #+#             */
/*   Updated: 2022/07/05 17:32:16 by eelhasni         ###   ########.fr       */
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
