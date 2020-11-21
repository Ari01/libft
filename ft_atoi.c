/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:13:29 by user42            #+#    #+#             */
/*   Updated: 2020/11/18 16:09:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

static int	ft_issign(char c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (-1);
	return (0);
}

static int	convert_atoi(const char *sub, size_t len, int sign)
{
	int	res;
	int pow;

	res = 0;
	pow = 1;
	while (len--)
	{
		res += (sub[len] -'0') * pow;
		pow *= 10;
	}
	if (sign)
		res *= sign;
	return (res);
}

int			ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		start;
	size_t	substring_len;
	char	*substring;

	i = 0;
	substring_len = 0;
	while (ft_isspace(nptr[i]))
		i++;
	sign = ft_issign(nptr[i]);
	if (sign)
		i++;
	start = i;
	while (ft_isdigit(nptr[i]))
		i++;
	substring_len = i - start;
	substring = ft_substr(nptr, start, substring_len);
	if (substring)
		return (convert_atoi(substring, substring_len, sign));
	return (0);
}
