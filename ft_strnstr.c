/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 20:29:37 by user42            #+#    #+#             */
/*   Updated: 2020/11/30 12:20:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*occ;
	size_t	i;
	size_t	j;
	size_t	biglen;

	i = 0;
	j = 0;
	biglen = ft_strlen(big);
	if (!little[j])
		return ((char *)big);
	while (big[i] && i < len && i < biglen)
	{
		while (big[i] && big[i] != little[j] && i < len)
			i++;
		occ = (char *)&big[i];
		while (big[i] && little[j] && big[i] == little[j] && i < len)
		{
			i++;
			j++;
		}
		if (!little[j])
			return (occ);
		i = occ - big + 1;
		j = 0;
	}
	return (NULL);
}
