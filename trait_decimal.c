/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trait_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:52:46 by aamzil            #+#    #+#             */
/*   Updated: 2019/11/23 18:08:15 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_decimal(unsigned nb)
{
	if (nb / 10)
		print_decimal(nb / 10);
	my_putchar('0' + nb % 10);
}

void	print_dec_dir(int dir, int nb_sign, int nb, unsigned int nb_rec)
{
	if ((g_zero && !g_point && !g_min_sign && g_first_ast >= 0) || (g_zero
		&& g_point && !g_min_sign && g_second_ast < 0 && g_first_ast >= 0))
	{
		g_precision = g_min_width;
		g_min_width = 0;
	}
	if (dir > 0)
	{
		print_space(g_min_width);
		if (nb_sign == '-')
			my_putchar('-');
		print_zero(g_precision);
		if (!(g_point && !nb && g_second_ast == 0))
			print_decimal(nb_rec);
	}
	else if (dir < 0)
	{
		if (nb_sign == '-')
			my_putchar('-');
		print_zero(g_precision);
		if (!(g_point && !nb && g_second_ast == 0))
			print_decimal(nb_rec);
		print_space(g_min_width);
	}
}

void	trait_decimal(void)
{
	int				dir;
	int				nb;
	int				len;
	int				nb_sign;
	unsigned int	nb_rec;

	g_first_ast = (g_first_ast) ? va_arg(g_ap, int) : g_first_ast;
	g_second_ast = (g_second_ast) ? va_arg(g_ap, int) : g_second_ast;
	g_min_width = (g_first_ast) ? g_first_ast : g_min_width;
	g_precision = (g_second_ast) ? g_second_ast : g_precision;
	g_precision = (g_precision <= 0) ? 0 : g_precision;
	dir = (g_min_sign || g_min_width < 0) ? -1 : 1;
	g_min_width = (g_min_width < 0) ? -g_min_width : g_min_width;
	nb = va_arg(g_ap, int);
	nb_sign = (nb >= 0) ? '+' : '-';
	nb_rec = (nb >= 0) ? nb : -nb;
	len = count_for_dec(nb, 10);
	len = (g_point && !nb && g_second_ast == 0) ? 0 : len;
	g_precision = ((int)len >= g_precision) ? 0 : g_precision - len;
	g_min_width -= (nb_sign == '-') ? 1 : 0;
	g_min_width = g_min_width - len - g_precision;
	print_dec_dir(dir, nb_sign, nb, nb_rec);
}
