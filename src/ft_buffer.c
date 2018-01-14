/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:19:59 by msteffen          #+#    #+#             */
/*   Updated: 2018/01/12 16:27:51 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"

t_buffer	*buffer_init()
{
	t_buffer *buffer;

	buffer = (t_buffer*)malloc(sizeof(t_buffer));
	buffer->buffer_str = ft_strnew(32);
	buffer->allocated = 32;
	buffer->len = 0;
	return (buffer);
}

int realloc_buffer(t_buffer *buffer, int target_size)
{
	char *tmp;

	if ((int)ft_strlen(buffer->buffer_str) + target_size < buffer->allocated)
		return (1);
	if ((tmp = ft_strnew(ft_strlen(buffer->buffer_str))) == NULL)
		return (0);
	ft_strcpy(tmp, buffer->buffer_str);
	free(buffer->buffer_str);
	buffer->allocated = buffer->allocated + target_size + 2;
	if ((buffer->buffer_str = ft_strnew(buffer->allocated)) == NULL)
		return (0);
	ft_strcpy(buffer->buffer_str, tmp);
	free(tmp);
	return (1);
}

int ft_buffer_putchar(t_buffer *buffer, char c)
{
	realloc_buffer(buffer, 10);
	buffer->buffer_str[ft_strlen(buffer->buffer_str)] = c;
	buffer->buffer_str[ft_strlen(buffer->buffer_str) + 1] = 0;
	buffer->len += 1;
	return (1);
}

int	ft_buffer_putnchar(t_buffer *buffer, char c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_buffer_putchar(buffer, c);
		i++;
	}
	return (1);
}

int ft_buffer_putstr(t_buffer *buffer, char *str)
{
	if (realloc_buffer(buffer, ft_strlen(str)) == 0)
		return (0);
	ft_strcat(buffer->buffer_str, str);
	buffer->len += ft_strlen(str);
	return (1);
}

int	ft_buffer_putnstr(t_buffer *buffer, char *str, int n)
{
	if (n < 0)
		return (-1);
	if (realloc_buffer(buffer, ft_strlen(str) - n) == 0)
		return (0);
	ft_strncat(buffer->buffer_str, str, n);
	if (n > (int)ft_strlen(str))
		buffer->len += (int)ft_strlen(str);
	else
		buffer->len += n;
	return (1);
}
