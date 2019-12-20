/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trait_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 23:37:09 by aamzil            #+#    #+#             */
/*   Updated: 2019/11/24 15:44:23 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(size_t nb, char c)
{
	if (nb / 16)
		print_pointer(nb / 16, c);
	if (nb % 16 >= 10)
		my_putchar(nb % 16 + c - 10);
	else
		my_putchar(nb % 16 + '0');
}

void	print_pointer_dir(int dir, size_t nb_rec, char c)
{
	if (dir > 0)
	{
		print_space(g_min_width);
		my_putchar('0');
		my_putchar('x');
		if (!(g_point && !nb_rec && g_second_ast == 0))
			print_pointer(nb_rec, c);
	}
	else if (dir < 0)
	{
		my_putchar('0');
		my_putchar('x');
		if (!(g_point && !nb_rec && g_second_ast == 0))
			print_pointer(nb_rec, c);
		print_space(g_min_width);
	}
}

void	trait_pointer(void)
{
	int		dir;
	int		len;
	size_t	nb_rec;

	g_first_ast = (g_first_ast) ? va_arg(g_ap, int) : g_first_ast;
	g_min_width = (g_first_ast) ? g_first_ast : g_min_width;
	dir = (g_min_sign || g_min_width < 0) ? -1 : 1;
	g_min_width = (g_min_width < 0) ? -g_min_width : g_min_width;
	nb_rec = (size_t)va_arg(g_ap, void*);
	len = count_for_hexa(nb_rec, 16) + 2;
	len = (g_point && !nb_rec && g_second_ast == 0) ? 2 : len;
	g_min_width = g_min_width - len - g_precision;
	print_pointer_dir(dir, nb_rec, 'a');
}
