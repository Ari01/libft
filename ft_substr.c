/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:33:21 by user42            #+#    #+#             */
/*   Updated: 2020/11/18 16:04:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	sub = malloc(sizeof(*sub) * len);
	if (!sub || !s)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		sub[i] = s[start++];
		i++;
	}
	sub[i] = 0;
	return (sub);
}
