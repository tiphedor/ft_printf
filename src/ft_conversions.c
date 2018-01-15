/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:06:27 by msteffen          #+#    #+#             */
/*   Updated: 2018/01/15 14:19:16 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_conversions.h"

int ft_def_conv_placeholder(t_flags *f, va_list *v, t_buffer *b)
{
	(void)f; (void)v; (void)b;
	return (-2);
}

int ft_conversion_percent(t_flags *flags, va_list *args, t_buffer *buffer)
{
	if (flags->width != 0 && !flags->dash)
		ft_buffer_putnchar(buffer, (flags->zero) ? '0' : ' ', flags->width - 1);
	ft_buffer_putchar(buffer, '%');
	if (flags->width != 0 && flags->dash)
		ft_buffer_putnchar(buffer, ' ', flags->width - 1);
	(void)args;
	return (1);
}

void ft_init_conversions(int (*conversions[256])(t_flags *, va_list *, t_buffer *))
{
	(void)conversions;
	int i;

	i = 0;
	while (i < 256)
		conversions[i++] = &ft_def_conv_placeholder;
	conversions['%'] = &ft_conversion_percent;

	conversions['d'] = &ft_conversion_d;
	conversions['D'] = &ft_conversion_cd;
	conversions['u'] = &ft_conversion_u;
	conversions['U'] = &ft_conversion_cu;
	conversions['i'] = &ft_conversion_d;

	conversions['x'] = &ft_conversion_x;
	conversions['X'] = &ft_conversion_cx;
	conversions['o'] = &ft_conversion_o;
	conversions['O'] = &ft_conversion_co;

	conversions['c'] = &ft_conversion_c;
	conversions['s'] = &ft_conversion_s;

	conversions['p'] = &ft_conversion_p;

	conversions['C'] = &ft_conversion_cc;
	conversions['S'] = &ft_conversion_cs;


}
