/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:05:59 by msteffen          #+#    #+#             */
/*   Updated: 2018/01/15 13:42:31 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_unicode.h"
#include <stdio.h>

int ft_get_utf_len(unsigned long nb)
{
	if (nb >= 0xd800 && nb <= 0xDFFF)
		return (-1);
	if (nb <= 0x7F)
		return (1);
	else if (nb <= 0x7FF)
		return (2);
	else if (nb <= 0xFFFF)
		return (3);
	else if (nb <= 0x10FFFF)
		return (4);
	return (-1);
}

int print_bytes(unsigned char *bytes, int bytes_count, t_buffer *buffer)
{
	if (bytes_count == 4 && MB_CUR_MAX >= 4)
	{
		ft_buffer_putchar(buffer, bytes[3]);
		ft_buffer_putchar(buffer, bytes[2]);
		ft_buffer_putchar(buffer, bytes[1]);
		ft_buffer_putchar(buffer, bytes[0]);
		return (1);
	}

	if (bytes_count == 3 && MB_CUR_MAX >= 3)
	{
		ft_buffer_putchar(buffer, bytes[3]);
		ft_buffer_putchar(buffer, bytes[2]);
		ft_buffer_putchar(buffer, bytes[1]);
		return (1);
	}

	if (bytes_count == 2 && MB_CUR_MAX >= 2)
	{
		ft_buffer_putchar(buffer, bytes[3]);
		ft_buffer_putchar(buffer, bytes[2]);
		return (1);
	}
	return (-1);
}

int ft_put_unicode_lowrange(unsigned long nb, t_buffer *buffer)
{
	unsigned char	utf_8[4];

	utf_8[3] = 0xC0 | (uint8_t) ((nb >> 6) & 0x1F);
	utf_8[2] = 0x80 | (uint8_t) (nb & 0x3F);
	return (print_bytes(utf_8, 2, buffer));
}

int ft_put_unicode_midrange(unsigned long nb, t_buffer *buffer)
{
	unsigned char	utf_8[4];

	utf_8[3] = 0xE0 | (uint8_t) ((nb >> 12) & 0x0F);
    utf_8[2] = 0x80 | (uint8_t) ((nb >> 6) & 0x3F);
    utf_8[1] = 0x80 | (uint8_t) (nb & 0x3F);
	return (print_bytes(utf_8, 3, buffer));
}

int ft_put_unicode_highrange(unsigned long nb, t_buffer *buffer)
{
	unsigned char	utf_8[4];

	utf_8[0] = 0x80 | (uint8_t) (nb & 0x3F);
	utf_8[1] = 0x80 | (uint8_t) ((nb >> 6) & 0x3F);
	utf_8[2] = 0x80 | (uint8_t) ((nb >> 12) & 0x3F);
	utf_8[3] = 0xF0 | (uint8_t) ((nb >> 18) & 0x07);
	return (print_bytes(utf_8, 4, buffer));
}

int ft_putunicode_char(unsigned long nb, t_buffer *buffer)
{
	if (nb >= 0xd800 && nb <= 0xDFFF)
		return (-1);
	if (nb <= 0x7F)
		return (ft_buffer_putchar(buffer, nb));
	else if (nb <= 0x7FF)
		return (ft_put_unicode_lowrange(nb, buffer));
	else if (nb <= 0xFFFF)
	{
		return (ft_put_unicode_midrange(nb, buffer));
	}
	else if (nb <= 0x10FFFF)
	{
		return (ft_put_unicode_highrange(nb, buffer));
	}

	return (-1);
}

int ft_putunicode_str(wchar_t *str, t_buffer *buffer)
{
	int i;

	i = 0;
	while (str[i]) {
		if (ft_putunicode_char(str[i], buffer) == -1)
			return (-1);
		i++;
	}
	return (1);
}
