/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:08:38 by jcheron           #+#    #+#             */
/*   Updated: 2024/10/21 12:03:47 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include "libft.h"

int	main(void)
{
	char *ptr = "coucou";

	ft_printf("My Char test   : %c !\n", 'W');
	printf("Printf Char    : %c !\n", 'W');

	printf("------------------------------------------\n");

	ft_printf("My String test : %s\n", "Hello, world!");
	printf("Printf String  : %s\n", "Hello, world!");

	printf("------------------------------------------\n");

	ft_printf("My Number Test : %d\n", 42);
	printf("Printf Number  : %d\n", 42);

	printf("------------------------------------------\n");

	ft_printf("My Percent test : %%\n");
	printf("Printf Percent  : %%\n");

	printf("------------------------------------------\n");

	ft_printf("My hex test : %x\n", 4654);
	printf("Printf hex  : %x\n", 4654);

	printf("------------------------------------------\n");

	ft_printf("My HEX test : %X\n", 4654);
	printf("Printf HEX  : %X\n", 4654);

	printf("------------------------------------------\n");

	ft_printf("My ptr test : %p\n", ptr);
	printf("Printf ptr  : %p\n", ptr);

	printf("------------------------------------------\n");

	ft_printf("My unsigned test : %u\n", -1);
	printf("Printf unsigned  : %u\n", -1);

	printf("------------------------------------------\n");

	return (0);
}
