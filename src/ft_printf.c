/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:45:35 by jcheron           #+#    #+#             */
/*   Updated: 2024/10/22 18:09:09 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

static int	ft_formats(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_print_c(va_arg(args, int));
	else if (format == 's')
		len += ft_print_s(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		len += ft_print_d(va_arg(args, int));
	else if (format == '%')
		len += ft_print_pct();
	else if (format == 'x' || format == 'X')
		len += ft_print_x(va_arg(args, unsigned int), format);
	else if (format == 'p')
		len += ft_print_p(va_arg(args, uintptr_t));
	else if (format == 'u')
		len += ft_print_u(va_arg(args, unsigned int));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
