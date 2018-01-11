/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 13:58:21 by msteffen          #+#    #+#             */
/*   Updated: 2018/01/11 17:29:15 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list			args;

	va_start(args, format);
	return (ft_printf_tofd(format, 1, &args));
}

int ft_printf_fd(int fd, const char *format, ...)
{
	va_list			args;
	
	va_start(args, format);
	return (ft_printf_tofd(format, fd, &args));
}

int	ft_printf_tofd(const char *format, int fd, va_list *args)
{
	unsigned int	i;
	int				(*conversions[256]) (t_flags *, va_list *, t_buffer *);
	t_buffer		*buffer;
	t_flags			flags;
	int				ret;

	i = 0;
	buffer = buffer_init();
	ft_init_conversions(conversions);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i += ft_parse_flags(format + i + 1, &flags);
			ret = conversions[(int)format[i]](&flags, args, buffer);
			if (ret == -2 && format[i - 1])
				i--;
			else if (ret == -1)
				return (-1);
		}
		else
			ft_buffer_putchar(buffer, format[i]);
		i++;
	}
	ft_putstr_fd(buffer->buffer_str, fd);
	int a = buffer->len;
	free(buffer->buffer_str);
	free(buffer);
	return (a);
}
