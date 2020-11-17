/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:19:10 by user42            #+#    #+#             */
/*   Updated: 2020/11/16 17:35:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*destcpy;
	unsigned char	*srccpy;

	destcpy = (unsigned char *)dest;
	srccpy = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		destcpy[i] = srccpy[i];
		i++;
	}
	return (dest);
}
