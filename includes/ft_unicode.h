/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:05:42 by msteffen          #+#    #+#             */
/*   Updated: 2018/01/11 13:45:56 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UNICODE_H
# define FT_UNICODE_H

# include "ft_buffer.h"
# include <wchar.h>

int print_bytes(unsigned char *bytes, int bytes_count, t_buffer *buffer);
int ft_put_unicode_lowrange(unsigned long nb, t_buffer *buffer);
int ft_put_unicode_midrange(unsigned long nb, t_buffer *buffer);
int ft_put_unicode_highrange(unsigned long nb, t_buffer *buffer);
int ft_putunicode_char(unsigned long nb, t_buffer *buffer);
int ft_putunicode_str(wchar_t *str, t_buffer *buffer);

#endif
