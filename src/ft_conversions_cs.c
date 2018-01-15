/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_cs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:26:29 by msteffen          #+#    #+#             */
/*   Updated: 2018/01/15 14:56:03 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_conversions_cs.h"

int ft_conversion_c(t_flags *flags, va_list *args, t_buffer *buffer)
{
	char c;

	if (flags->l)
		return (ft_conversion_cc(flags, args, buffer));
	c = va_arg(*args, int);
	if (!flags->dash && flags->width > 1)
		ft_buffer_putnchar(buffer, ' ', flags->width - 1);
	ft_buffer_putchar(buffer, c);
	if (flags->dash && flags->width > 1)
		ft_buffer_putnchar(buffer, ' ', flags->width - 1);
	return (1);
}

int ft_conversion_s(t_flags *flags, va_list *args, t_buffer *buffer)
{
	char *c;
	int nb_spaces;

	if (flags->l)
		return (ft_conversion_cs(flags, args, buffer));
	c = va_arg(*args, char*);
	if (c == NULL)
	{
		nb_spaces = flags->width - 6;
		if (flags->precision != -1)
			nb_spaces += 6 - flags->precision;
		if (!flags->dash)
			ft_buffer_putnchar(buffer, ' ', nb_spaces);
		ft_buffer_putnstr(buffer, "(null)", (flags->precision == -1) ? 6 : flags->precision);
		if (flags->dash)
			ft_buffer_putnchar(buffer, ' ', nb_spaces);
		return (1);
	}
	if (flags->width == 0)
		nb_spaces = 0;
	else
		nb_spaces = flags->width - ft_strlen(c);
	if (flags->precision == -1 || flags->precision > (int)ft_strlen(c))
	{
		if (!flags->dash)
			ft_buffer_putnchar(buffer, ' ', nb_spaces);
		ft_buffer_putstr(buffer, c);
		if (flags->dash)
			ft_buffer_putnchar(buffer, ' ', nb_spaces);
	}
	else
	{
		if (flags->width != 0)
			nb_spaces += ft_strlen(c) - flags->precision;
		if (!flags->dash)
			ft_buffer_putnchar(buffer, ' ', nb_spaces);
		ft_buffer_putnstr(buffer, c, flags->precision);
		if (flags->dash)
			ft_buffer_putnchar(buffer, ' ', nb_spaces);
	}
	return (1);
}

int ft_conversion_cc(t_flags *flags, va_list *args, t_buffer *buffer)
{
	wchar_t c;
	int nb_spaces;

	c = (wchar_t)va_arg(*args, wchar_t);
	nb_spaces = flags->width - 1;
	if (ft_get_utf_len(c) > 1)
		nb_spaces -= ft_get_utf_len(c) - 1;
	if (!flags->dash && flags->width > 1)
		ft_buffer_putnchar(buffer, ' ', nb_spaces);
	if (ft_putunicode_char(c, buffer) == -1)
		return (-1);
	if (flags->dash && flags->width > 1)
		ft_buffer_putnchar(buffer, ' ', nb_spaces);
	return (1);
}

int ft_conversion_cs(t_flags *flags, va_list *args, t_buffer *buffer)
{
	wchar_t *c;

	c = (wchar_t*)va_arg(*args, wchar_t*);
	if (c == 0)
		ft_buffer_putstr(buffer, "(null)");
	else
		if (ft_putunicode_str(c, buffer) == -1)
			return (-1);
	(void)flags;
	return (0);
}
