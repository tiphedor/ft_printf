/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_ox.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:20:51 by msteffen          #+#    #+#             */
/*   Updated: 2018/01/11 15:47:45 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_conversions_ox.h"

int ft_conversion_x(t_flags *flags, va_list *args, t_buffer *buffer)
{
	uint64_t nb;
	char *nb_str;
	int nb_spaces;
	int nb_zeros;

	nb = ft_cast_unsigned(flags, args);
	nb_str = ft_itoau64_base(nb, "0123456789abcdef");
	nb_zeros = flags->precision - ft_strlen(nb_str);
	nb_spaces = flags->width - ft_strlen(nb_str) - (flags->hash) - (flags->hash);
	if (nb_zeros > 0)
		nb_spaces -= nb_zeros;
	nb_zeros = (nb_zeros < 0) ? 0 : nb_zeros;
	if (flags->zero)
	{
		nb_zeros += nb_spaces;
		nb_spaces = 0;
	}
	ft_buffer_putnchar(buffer, ' ', nb_spaces);
	if (flags->hash && nb != 0)
	{
		ft_buffer_putstr(buffer, "0x");
	}
	ft_buffer_putnchar(buffer, '0', nb_zeros);
	if (flags->precision != 0 || nb != 0)
		ft_buffer_putstr(buffer, nb_str);
	return (1);
}

int ft_conversion_cx(t_flags *flags, va_list *args, t_buffer *buffer)
{
	uint64_t nb;
	char *nb_str;
	int nb_spaces;
	int nb_zeros;

	nb = ft_cast_unsigned(flags, args);
	nb_str = ft_itoau64_base(nb, "0123456789ABCDEF");
	nb_zeros = flags->precision - ft_strlen(nb_str);
	nb_spaces = flags->width - ft_strlen(nb_str) - (flags->hash) - (flags->hash);
	if (nb_zeros > 0)
		nb_spaces -= nb_zeros;
	nb_zeros = (nb_zeros < 0) ? 0 : nb_zeros;
	if (flags->zero)
	{
		nb_zeros += nb_spaces;
		nb_spaces = 0;
	}
	ft_buffer_putnchar(buffer, ' ', nb_spaces);
	if (flags->hash && nb != 0)
		ft_buffer_putstr(buffer, "0X");
	ft_buffer_putnchar(buffer, '0', nb_zeros);
	if (flags->precision != 0 || nb != 0)
		ft_buffer_putstr(buffer, nb_str);
	return (1);
}

int ft_conversion_o(t_flags *flags, va_list *args, t_buffer *buffer)
{
	uint64_t nb;
	char *nb_str;
	int nb_spaces;
	int nb_zeros;

	nb = ft_cast_unsigned(flags, args);
	nb_str = ft_itoau64_base(nb, "01234567");
	nb_zeros = flags->precision - ft_strlen(nb_str);
	nb_spaces = flags->width - ft_strlen(nb_str) - (flags->hash);
	if (nb_zeros > 0)
		nb_spaces -= nb_zeros;
	nb_zeros = (nb_zeros < 0) ? 0 : nb_zeros;
	if (flags->zero)
	{
		nb_zeros += nb_spaces;
		nb_spaces = 0;
	}
	ft_buffer_putnchar(buffer, ' ', nb_spaces);
	if (flags->hash && (nb != 0 || flags->precision != -1))
		ft_buffer_putstr(buffer, "0");
	ft_buffer_putnchar(buffer, '0', nb_zeros);
	if (flags->precision != 0 || nb != 0)
		ft_buffer_putstr(buffer, nb_str);
	return (1);
}

int ft_conversion_co(t_flags *flags, va_list *args, t_buffer *buffer)
{
	flags->hh = 0;
	flags->j = 0;
	flags->z = 0;
	flags->hh = 0;
	flags->h = 0;
	flags->l = 0;
	flags->ll = 1;
	return (ft_conversion_o(flags, args, buffer));
}
