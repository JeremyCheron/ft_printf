/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 08:02:34 by jcheron           #+#    #+#             */
/*   Updated: 2024/10/17 08:04:13 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	ft_strrev(char *str)
{
	size_t	len;
	size_t	i;
	char	bfr;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		bfr = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = bfr;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		neg;
	size_t	len;

	neg = (n < 0);
	str = ft_calloc(11 + neg, sizeof(*str));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	len = 0;
	while (n != 0)
	{
		str[len++] = '0' + ft_abs(n % 10);
		n /= 10;
	}
	if (neg)
		str[len] = '-';
	ft_strrev(str);
	return (str);
}
