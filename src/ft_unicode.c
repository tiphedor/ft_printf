/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:05:59 by msteffen          #+#    #+#             */
/*   Updated: 2018/01/11 13:54:23 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_unicode.h"
#include <stdio.h>
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
	unsigned char	bytes[4];
	unsigned char	utf_8[4];
	int				i;
	int				y;

	bytes[2] = 0x80;
	bytes[3] = 0xC0;
	i = 11;
	y = 5;
	while (i != 5)
		bytes[3] = (((nb >> i--) & 1) << y--) | bytes[3];
	y = 5;
	while (i != -1)
		bytes[2] = (((nb >> i--) & 1) << y--) | bytes[2];
	utf_8[3] = '\x00' + bytes[3];
	utf_8[2] = '\x00' + bytes[2];
	return (print_bytes(utf_8, 2, buffer));
}

int ft_put_unicode_midrange(unsigned long nb, t_buffer *buffer)
{
	unsigned char	bytes[4];
	unsigned char	utf_8[4];
	int				i;
	int				y;

	bytes[1] = 0x80;
	bytes[2] = 0x80;
	bytes[3] = 0xE0;
	i = 15;
	y = 3;
	while (i != 11)
		bytes[3] = (((nb >> i--) & 1) << y--) | bytes[3];
	y = 5;
	while (i != 5)
		bytes[2] = (((nb >> i--) & 1) << y--) | bytes[2];
	y = 5;
	while (i != -1)
		bytes[1] = (((nb >> i--) & 1) << y--) | bytes[1];
	utf_8[3] = '\x00' + bytes[3];
	utf_8[2] = '\x00' + bytes[2];
	utf_8[1] = '\x00' + bytes[1];
	return (print_bytes(utf_8, 3, buffer));
}

int ft_put_unicode_highrange(unsigned long nb, t_buffer *buffer)
{
	unsigned char	bytes[4];
	unsigned char	utf_8[4];
	int				i;
	int				y;

	bytes[0] = 0x80;
	bytes[1] = 0x80;
	bytes[2] = 0x80;
	bytes[3] = 0xf0;
	i = 20;
	y = 2;

	while (i != 17)
		bytes[3] = (((nb >> i--) & 1) << y--) | bytes[3];
	y = 5;
	while (i != 11)
		bytes[2] = (((nb >> i--) & 1) << y--) | bytes[2];
	y = 5;
	while (i != 5)
		bytes[1] = (((nb >> i--) & 1) << y--) | bytes[1];
	y = 5;
	while (i != 0)
		bytes[0] = (((nb >> i--) & 1) << y--) | bytes[0];
	utf_8[3] = '\x00' + bytes[3];
	utf_8[2] = '\x00' + bytes[2];
	utf_8[1] = '\x00' + bytes[1];
	utf_8[0] = '\x00' + bytes[0];
	return (print_bytes(utf_8, 4, buffer));
}

int ft_putunicode_char(unsigned long nb, t_buffer *buffer)
{
	if (nb <= 0x0000007F)
	{
		ft_buffer_putchar(buffer, nb);
		return (1);
	}
	else if (nb >= 0x00000080 && nb <= 0x000007FF)
		return (ft_put_unicode_lowrange(nb, buffer));
	else if (nb >= 0x00000800 && nb <= 0x0000FFFF)
		return (ft_put_unicode_midrange(nb, buffer));
	else if (nb >= 0x00010000 && nb <= 0x001FFFFF)
		return (ft_put_unicode_highrange(nb, buffer));
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
