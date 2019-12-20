/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision_and_width.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 00:51:11 by aamzil            #+#    #+#             */
/*   Updated: 2019/11/23 20:37:57 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_min_width(const char *frm, int i)
{
	if (ft_isdigit(frm[i]))
	{
		g_min_width = ft_atoi(frm + i);
		i = skip_numbers(frm, i);
	}
	return (i);
}

int		get_precision(const char *frm, int i)
{
	if (ft_isdigit(frm[i]))
	{
		g_precision = ft_atoi(frm + i);
		i = skip_numbers(frm, i);
	}
	return (i);
}
