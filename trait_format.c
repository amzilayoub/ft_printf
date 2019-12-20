/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trait_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:17:13 by aamzil            #+#    #+#             */
/*   Updated: 2019/11/23 23:17:59 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		skip_sign(const char *frm, int i)
{
	if (frm[i] == '-')
		while (frm[i] == '-')
			i++;
	return (i);
}

int		skip_numbers(const char *frm, int i)
{
	while (ft_isdigit(frm[i]))
		i++;
	return (i);
}

int		is_valid(void)
{
	if (g_format == 'i' || g_format == 'd' || g_format == 'u'
			|| g_format == 'x' || g_format == 'X' || g_format == 'p' ||
			g_format == 's' || g_format == '%' || g_format == 'c')
		return (1);
	else
		return (0);
}

int		trait_format(const char *frm)
{
	int		i;
	int		is_true;

	i = 0;
	is_true = 1;
	while (frm[i] == '%')
		i++;
	g_percent = (i % 2 == 0) ? 1 : 0;
	print_percent(i / 2);
	if (i % 2 == 0)
		return (i - 1);
	g_min_sign = (frm[i] == '-') ? 1 : g_min_sign;
	i = skip_sign(frm, i);
	g_zero = (frm[i] == '0') ? 1 : g_zero;
	i = get_min_width(frm, i);
	g_first_ast = (frm[i] == '*') ? ++i : g_first_ast;
	g_point = (frm[i] == '.') ? ++i : g_point;
	i = get_precision(frm, i);
	g_second_ast = (frm[i] == '*') ? ++i : g_second_ast;
	g_format = frm[i];
	print_format();
	return (i);
}

void	print_percent(int i)
{
	while (i--)
		my_putchar('%');
}
