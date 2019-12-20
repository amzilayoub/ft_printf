/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trait_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 23:56:22 by aamzil            #+#    #+#             */
/*   Updated: 2019/11/23 18:08:49 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_n_char(char *str, int len)
{
	int i;

	i = -1;
	while (str[++i] && i < len)
		my_putchar(str[i]);
}

void	print_string_dir(int dir, char *str)
{
	if (dir > 0)
	{
		print_space(g_min_width);
		print_n_char(str, g_precision);
	}
	else if (dir < 0)
	{
		print_n_char(str, g_precision);
		print_space(g_min_width);
	}
}

void	trait_string(void)
{
	int		dir;
	size_t	len;
	char	*str;

	g_first_ast = (g_first_ast) ? va_arg(g_ap, int) : g_first_ast;
	g_second_ast = (g_second_ast) ? va_arg(g_ap, int) : g_second_ast;
	g_min_width = (g_first_ast) ? g_first_ast : g_min_width;
	g_precision = (g_second_ast) ? g_second_ast : g_precision;
	str = va_arg(g_ap, char*);
	str = (!str) ? "(null)" : str;
	len = ft_strlen(str);
	dir = (g_min_sign || g_min_width < 0) ? -1 : 1;
	g_min_width = (g_min_width < 0) ? -g_min_width : g_min_width;
	if (!((int)len >= g_precision && g_precision >= 0 && g_point))
		g_precision = len;
	g_min_width = g_min_width - g_precision;
	print_string_dir(dir, str);
}
