/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:00:20 by user42            #+#    #+#             */
/*   Updated: 2020/11/16 18:22:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
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
		if (destcpy[i] == c)
			return (&destcpy[i + 1]);
		i++;
	}
	return (NULL);
}
