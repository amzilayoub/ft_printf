/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trait_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:42:50 by aamzil            #+#    #+#             */
/*   Updated: 2019/11/22 23:38:22 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_uint_dir(int dir, unsigned int nb_rec)
{
	if ((g_zero && !g_point && !g_min_sign && g_first_ast >= 0) || (g_point
		&& g_zero && g_second_ast < 0 && !g_min_sign && g_first_ast >= 0))
	{
		g_precision = g_min_width;
		g_min_width = 0;
	}
	if (dir > 0)
	{
		print_space(g_min_width);
		print_zero(g_precision);
		if (!(g_point && !nb_rec && g_second_ast == 0))
			print_decimal(nb_rec);
	}
	else if (dir < 0)
	{
		print_zero(g_precision);
		if (!(g_point && !nb_rec && g_second_ast == 0))
			print_decimal(nb_rec);
		print_space(g_min_width);
	}
}

void	trait_uint(void)
{
	int				dir;
	int				len;
	unsigned int	nb_rec;

	g_first_ast = (g_first_ast) ? va_arg(g_ap, int) : g_first_ast;
	g_second_ast = (g_second_ast) ? va_arg(g_ap, int) : g_second_ast;
	g_min_width = (g_first_ast) ? g_first_ast : g_min_width;
	g_precision = (g_second_ast) ? g_second_ast : g_precision;
	g_precision = (g_precision <= 0) ? 0 : g_precision;
	dir = (g_min_sign || g_min_width < 0) ? -1 : 1;
	g_min_width = (g_min_width < 0) ? -g_min_width : g_min_width;
	nb_rec = va_arg(g_ap, unsigned int);
	len = count_for_uint(nb_rec, 10);
	len = (g_point && !nb_rec && g_second_ast == 0) ? 0 : len;
	g_precision = (len >= g_precision) ? 0 : g_precision - len;
	g_min_width = g_min_width - len - g_precision;
	print_uint_dir(dir, nb_rec);
}
