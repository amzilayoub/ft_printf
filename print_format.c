/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:50:33 by aamzil            #+#    #+#             */
/*   Updated: 2019/11/23 20:40:20 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_format(void)
{
	if (g_format == 'd' || g_format == 'i')
		trait_decimal();
	else if (g_format == 'u')
		trait_uint();
	else if (g_format == 'x')
		trait_lower_hexa();
	else if (g_format == 'X')
		trait_upper_hexa();
	else if (g_format == 'c')
		trait_char();
	else if (g_format == 'p')
		trait_pointer();
	else if (g_format == 's')
		trait_string();
	else if (g_format == '%')
		trait_percent();
}
