/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_ox.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:20:14 by msteffen          #+#    #+#             */
/*   Updated: 2018/01/11 12:53:32 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERSIONS_OX_H
# define FT_CONVERSIONS_OX_H

# include "ft_casts.h"
# include "ft_buffer.h"

int ft_conversion_x(t_flags *flags, va_list *args, t_buffer *buffer);
int ft_conversion_cx(t_flags *flags, va_list *args, t_buffer *buffer);
int ft_conversion_o(t_flags *flags, va_list *args, t_buffer *buffer);
int ft_conversion_co(t_flags *flags, va_list *args, t_buffer *buffer);

#endif
