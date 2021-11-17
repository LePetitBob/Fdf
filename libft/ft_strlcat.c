/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 19:23:09 by vduriez           #+#    #+#             */
/*   Updated: 2020/08/26 12:24:50 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;

	i = 0;
	while (i < size)
	{
		if (!dst[i])
		{
			i = 0;
			d_len = ft_strlen(dst);
			while (src[i] && i < (size - d_len) - 1)
			{
				dst[d_len + i] = src[i];
				++i;
			}
			dst[d_len + i] = 0;
			return (d_len + ft_strlen(src));
		}
		++i;
	}
	return (size + ft_strlen(src));
}
