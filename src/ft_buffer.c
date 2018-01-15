/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:19:59 by msteffen          #+#    #+#             */
/*   Updated: 2018/01/15 18:55:22 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"

t_buffer	*buffer_init(void)
{
	t_buffer *buffer;

	buffer = (t_buffer*)malloc(sizeof(t_buffer));
	buffer->buffer_str = ft_strnew(32);
	buffer->allocated = 32;
	buffer->len = 0;
	return (buffer);
}

int			realloc_buffer(t_buffer *buffer, int target_size)
{
	char *tmp;

	if ((int)ft_strlen(buffer->buffer_str) + target_size < buffer->allocated)
		return (1);
	if ((tmp = ft_strnew(ft_strlen(buffer->buffer_str))) == NULL)
		return (0);
	ft_memcpy(tmp, buffer->buffer_str, buffer->len);
	free(buffer->buffer_str);
	buffer->allocated = buffer->allocated + target_size + 2;
	if ((buffer->buffer_str = ft_strnew(buffer->allocated)) == NULL)
		return (0);
	ft_memcpy(buffer->buffer_str, tmp, buffer->len);
	free(tmp);
	return (1);
}

int			ft_dump_buffer(t_buffer *buffer, int fd)
{
	int i;
	int ret;

	i = 0;
	while (i < buffer->len)
	{
		ft_putchar_fd(buffer->buffer_str[i], fd);
		i++;
	}
	ret = buffer->len;
	free(buffer->buffer_str);
	free(buffer);
	return (ret);
}
