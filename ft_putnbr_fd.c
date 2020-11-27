/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:52:10 by user42            #+#    #+#             */
/*   Updated: 2020/11/27 19:19:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	unbr;
	char			c;

	unbr = n;
	if (n < 0)
	{
		unbr = -n;
		write(fd, "-", 1);
	}
	if (unbr < 10)
	{
		c = n - '0';
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		c = n % 10;
		write(fd, &c, 1);
	}
}
