/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_for_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:13:50 by aamzil            #+#    #+#             */
/*   Updated: 2019/11/24 21:41:40 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_for_dec(int p, int div)
{
	int i;

	i = 1;
	while ((p = (p / div)))
		i++;
	return (i);
}

int		count_for_uint(unsigned int p, int div)
{
	int i;

	i = 1;
	while ((p = (p / div)))
		i++;
	return (i);
}

int		count_for_hexa(size_t p, int div)
{
	int i;

	i = 1;
	while ((p = (p / div)))
		i++;
	return (i);
}
