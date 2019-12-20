/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trait_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 01:27:22 by aamzil            #+#    #+#             */
/*   Updated: 2019/11/23 00:50:51 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percent_dir(int dir, int min_width_rec)
{
	if (dir > 0)
	{
		if (g_zero && !g_min_sign && (g_first_ast > 0 || min_width_rec))
			print_zero(g_min_width);
		else
			print_space(g_min_width);
		my_putchar('%');
	}
	else if (dir < 0)
	{
		my_putchar('%');
		if (g_zero && !g_min_sign && (g_first_ast > 0 || min_width_rec))
			print_zero(g_min_width);
		else
			print_space(g_min_width);
	}
}

void	trait_percent(void)
{
	int dir;
	int	min_width_rec;

	min_width_rec = g_min_width;
	g_first_ast = (g_first_ast) ? va_arg(g_ap, int) : g_first_ast;
	g_min_width = (g_first_ast) ? g_first_ast : g_min_width;
	dir = (g_min_sign || g_min_width < 0) ? -1 : 1;
	g_min_width = (g_min_width < 0) ? -g_min_width : g_min_width;
	g_min_width = g_min_width - 1;
	print_percent_dir(dir, min_width_rec);
}
