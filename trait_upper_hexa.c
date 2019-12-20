/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trait_upper_hexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:48:43 by aamzil            #+#    #+#             */
/*   Updated: 2019/11/24 15:35:04 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	trait_upper_hexa(void)
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
	print_hexa_dir(dir, nb_rec, 'A');
}
