/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 20:29:37 by user42            #+#    #+#             */
/*   Updated: 2020/11/17 20:49:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char *occ;

	if (!little[0])
		return ((char *)big);
	while (*big && *big != *little && len--)
		big++;
	occ = (char *)big;
	while (*big && *little && *big == *little && len--)
	{
		big++;
		little++;
	}
	if (!little[0])
		return (occ);
	return (NULL);
}
