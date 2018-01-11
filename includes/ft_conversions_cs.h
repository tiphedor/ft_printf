/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_cs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:25:56 by msteffen          #+#    #+#             */
/*   Updated: 2018/01/11 13:10:07 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERSIONS_CS
# define FT_CONVERSIONS_CS

# include "ft_flags.h"
# include "ft_buffer.h"
# include "ft_casts.h"
# include "ft_unicode.h"
# include <stdarg.h>

int ft_conversion_c(t_flags *flags, va_list *args, t_buffer *buffer);
int ft_conversion_s(t_flags *flags, va_list *args, t_buffer *buffer);
int ft_conversion_cc(t_flags *flags, va_list *args, t_buffer *buffer);
int ft_conversion_cs(t_flags *flags, va_list *args, t_buffer *buffer);

#endif
