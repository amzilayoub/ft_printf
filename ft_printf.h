/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:17:40 by aamzil            #+#    #+#             */
/*   Updated: 2019/11/24 15:38:12 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>

# include <unistd.h>

# include "libft_src/libft.h"

int		g_min_width;
int		g_precision;
int		g_first_ast;
int		g_second_ast;
int		g_point;
int		g_min_sign;
int		g_printed_char;
char	g_format;
int		g_zero;
int		g_percent;
va_list	g_ap;

int		ft_printf(const char *frm, ...);
void	init();
void	print_zero(int i);
void	print_space(int i);
void	print_decimal(unsigned nb);
void	trait_decimal();
int		count_for_dec(int p, int div);
int		count_for_uint(unsigned int p, int div);
int		count_for_hexa(size_t p, int div);
void	my_putchar(char c);
void	print_format(void);
void	print_decimal(unsigned nb);
int		skip_sign(const char *frm, int i);
int		skip_numbers(const char *frm, int i);
int		get_nb(const char *frm, int i, int variable);
int		trait_format(const char *frm);
void	print_percent(int i);
void	print_decimal(unsigned nb);
void	trait_uint(void);
void	print_hexa(unsigned int nb, char c);
void	print_hexa_dir(int dir, unsigned int nb_rec, char c);
void	trait_lower_hexa(void);
void	trait_upper_hexa(void);
void	trait_char(void);
void	trait_pointer(void);
void	trait_string(void);
void	trait_percent(void);
int		get_min_width(const char *frm, int i);
int		get_precision(const char *frm, int i);

#endif
