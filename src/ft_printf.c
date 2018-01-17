/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 13:58:21 by msteffen          #+#    #+#             */
/*   Updated: 2018/01/16 09:43:19 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list			args;

	va_start(args, format);
	return (ft_printf_tofd(format, 1, &args));
}

int	ft_printf_fd(int fd, const char *format, ...)
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
	unsigned int	f_len;

	i = 0;
	buffer = buffer_init();
	ft_init_conversions(conversions);
	f_len = ft_strlen(format);
	while (i < f_len)
	{
		if (format[i] == '%')
		{
			i += ft_parse_flags(format + i + 1, &flags);
			flags.percent_holder = (format[i]) ? format[i] : -1;
			if (conversions[(int)format[i]](&flags, args, buffer) == -1)
				return (-1);
		}
		else
			ft_buffer_putchar(buffer, format[i]);
		i++;
	}
	return (ft_dump_buffer(buffer, fd));
}
