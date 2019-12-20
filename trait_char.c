/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trait_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 23:06:52 by aamzil            #+#    #+#             */
/*   Updated: 2019/11/23 20:40:44 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char_dir(int dir, int c)
{
	if (dir > 0)
	{
		print_space(g_min_width);
		my_putchar(c);
	}
	else if (dir < 0)
	{
		my_putchar(c);
		print_space(g_min_width);
	}
}

void	trait_char(void)
{
	int dir;
	int nb;

	g_first_ast = (g_first_ast) ? va_arg(g_ap, int) : g_first_ast;
	g_min_width = (g_first_ast) ? g_first_ast : g_min_width;
	dir = (g_min_sign || g_min_width < 0) ? -1 : 1;
	g_min_width = (g_min_width < 0) ? -g_min_width : g_min_width;
	nb = va_arg(g_ap, int);
	g_min_width = g_min_width - 1;
	print_char_dir(dir, nb);
}
