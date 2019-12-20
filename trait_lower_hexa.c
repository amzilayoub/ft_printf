/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trait_lower_hexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:13:38 by aamzil            #+#    #+#             */
/*   Updated: 2019/11/24 15:37:01 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hexa(unsigned int nb, char c)
{
	if (nb / 16)
		print_hexa(nb / 16, c);
	if (nb % 16 >= 10)
		my_putchar(nb % 16 + c - 10);
	else
		my_putchar(nb % 16 + '0');
}

void	print_hexa_dir(int dir, unsigned int nb_rec, char c)
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
			print_hexa(nb_rec, c);
	}
	else if (dir < 0)
	{
		print_zero(g_precision);
		if (!(g_point && !nb_rec && g_second_ast == 0))
			print_hexa(nb_rec, c);
		print_space(g_min_width);
	}
}

void	trait_lower_hexa(void)
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
	len = count_for_uint(nb_rec, 16);
	len = (g_point && !nb_rec && g_second_ast == 0) ? 0 : len;
	g_precision = (len >= g_precision) ? 0 : g_precision - len;
	g_min_width = g_min_width - len - g_precision;
	print_hexa_dir(dir, nb_rec, 'a');
}
