/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:18:09 by msteffen          #+#    #+#             */
/*   Updated: 2018/01/15 18:55:03 by msteffen         ###   ########.fr       */
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
	char	*buffer_str;
	int		allocated;
	int		len;
}				t_buffer;

t_buffer		*buffer_init(void);
int				realloc_buffer(t_buffer *buffer, int target_size);
int				ft_dump_buffer(t_buffer *buffer, int fd);

#endif
