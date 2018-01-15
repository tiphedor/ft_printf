/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_diu.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:05:12 by msteffen          #+#    #+#             */
/*   Updated: 2018/01/15 16:59:04 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_conversions_diu.h"

#include <stdio.h>


int ft_conversion_d(t_flags *flags, va_list *args, t_buffer *buffer)
{
	int64_t nb;
	char *nb_str;
	int nb_spaces;
	int nb_zeros;
	int negative;

	negative = 0;
	nb = ft_cast_signed(flags, args);
	if (nb < 0)
	{
		nb_str = ft_itoau64_base(-nb, "0123456789");
		negative = 1;
	}
	else
		nb_str = ft_itoa64_base(nb, "0123456789");
	nb_zeros = flags->precision - ft_strlen(nb_str);
	nb_spaces = flags->width - ft_strlen(nb_str) - (negative == 1) - (flags->space) - (flags->plus) + (flags->space && flags->plus);
	if (nb_zeros > 0)
		nb_spaces -= nb_zeros;
	if (nb_zeros < 0)
		nb_zeros = 0;
	if (!flags->dash && flags->zero && flags->precision == -1)
	{
		nb_zeros += nb_spaces;
		nb_spaces = 0;
	}

	if(!flags->dash)
		ft_buffer_putnchar(buffer, ' ', nb_spaces);
	if (negative)
		ft_buffer_putchar(buffer, '-');
	if (flags->plus && nb >= 0)
		ft_buffer_putchar(buffer, '+');
	else if (flags->space && nb >= 0)
		ft_buffer_putchar(buffer, ' ');
	ft_buffer_putnchar(buffer, '0', nb_zeros);
	if (flags->precision != 0 || nb != 0)
		ft_buffer_putstr(buffer, nb_str);
	if(flags->dash)
		ft_buffer_putnchar(buffer, ' ', nb_spaces);
	free(nb_str);
	return (1);
}

int ft_conversion_cd(t_flags *flags, va_list *args, t_buffer *buffer)
{
	flags->hh = 0;
	flags->j = 0;
	flags->z = 0;
	flags->hh = 0;
	flags->h = 0;
	flags->l = 0;
	flags->ll = 1;
	return (ft_conversion_d(flags, args, buffer));
}

int ft_conversion_u(t_flags *flags, va_list *args, t_buffer *buffer)
{
	uint64_t nb;
	char *nb_str;
	int nb_spaces;
	int nb_zeros;

	nb = ft_cast_unsigned(flags, args);
	nb_str = ft_itoau64_base(nb, "0123456789");
	nb_zeros = flags->precision - ft_strlen(nb_str);
	nb_spaces = flags->width - ft_strlen(nb_str);
	if (nb_zeros > 0)
		nb_spaces -= nb_zeros;
	nb_zeros = (nb_zeros < 0) ? 0 : nb_zeros;
	if (flags->zero && flags->precision == -1)
	{
		nb_zeros += nb_spaces;
		nb_spaces = 0;
	}
	if(!flags->dash)
		ft_buffer_putnchar(buffer, ' ', nb_spaces);
	ft_buffer_putnchar(buffer, '0', nb_zeros);
	if (flags->precision != 0 || nb != 0)
		ft_buffer_putstr(buffer, nb_str);
	if(flags->dash)
		ft_buffer_putnchar(buffer, ' ', nb_spaces);
	free(nb_str);
	return (1);
}

int ft_conversion_cu(t_flags *flags, va_list *args, t_buffer *buffer)
{
	flags->hh = 0;
	flags->j = 0;
	flags->z = 0;
	flags->hh = 0;
	flags->h = 0;
	flags->l = 0;
	flags->ll = 1;
	return (ft_conversion_u(flags, args, buffer));
}
