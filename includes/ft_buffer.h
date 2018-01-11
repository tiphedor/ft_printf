/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:18:09 by msteffen          #+#    #+#             */
/*   Updated: 2018/01/11 16:13:00 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUFFER_H
# define FT_BUFFER_H

# include "libft.h"
# include "string.h"
# include "ft_flags.h"
# include "nb_utils.h"
# include <stdint.h>
# include <stdlib.h>

typedef struct	s_buffer {
	char *buffer_str;
	int allocated;
	int len;
}				t_buffer;

t_buffer		*buffer_init();
int				realloc_buffer(t_buffer *buffer, int target_size);
int				ft_buffer_putnchar(t_buffer *buffer, char c, int n);
int				ft_buffer_putchar(t_buffer *buffer, char c);
int				ft_buffer_putstr(t_buffer *buffer, char *str);
int				ft_buffer_putnstr(t_buffer *buffer, char *str, int n);

#endif
