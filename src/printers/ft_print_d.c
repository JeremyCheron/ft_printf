/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:12:52 by jcheron           #+#    #+#             */
/*   Updated: 2024/10/27 19:00:02 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr(unsigned int n)
{
	if (n >= 10)
		return (ft_putnbr(n / 10) + ft_putnbr(n / 10))
	return (ft_print_c(n));
}

int	ft_print_d(int n)
{
	int	count;

	count = 0;
	count += ft_putnbr(n);
	if (count < 0)
		return (-1);
	return (count);
}
