/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:14:09 by aamzil            #+#    #+#             */
/*   Updated: 2019/11/23 23:25:23 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init(void)
{
	g_min_width = 0;
	g_precision = 0;
	g_first_ast = 0;
	g_second_ast = 0;
	g_point = 0;
	g_zero = 0;
	g_min_sign = 0;
	g_format = 0;
	g_percent = 0;
}

int		ft_printf(const char *frm, ...)
{
	size_t	i;
	size_t	len;

	i = 0;
	init();
	len = ft_strlen(frm);
	g_printed_char = 0;
	va_start(g_ap, frm);
	while (i < len && frm[i])
	{
		if (frm[i] == '%')
		{
			i += trait_format(frm + i);
			init();
		}
		else
			my_putchar(frm[i]);
		++i;
	}
	va_end(g_ap);
	return (g_printed_char);
}
