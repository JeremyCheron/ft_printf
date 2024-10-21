/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:46:33 by jcheron           #+#    #+#             */
/*   Updated: 2024/10/21 10:34:58 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
int		ft_print_c(char c);
int		ft_print_d(int n);
int		ft_print_s(char *s);
int		ft_print_x(unsigned int n, int format);
int		ft_print_pct(void);
int		ft_print_p(uintptr_t ptr);
int		ft_print_u(unsigned int n);

#endif
