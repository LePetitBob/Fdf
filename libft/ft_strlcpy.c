/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 19:57:41 by vduriez           #+#    #+#             */
/*   Updated: 2020/08/27 21:57:18 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t len;

	if (!dst)
		return (0);
	i = ft_strlen((char*)src);
	if (i >= size)
		len = size - 1;
	else
		len = i;
	if (size)
	{
		ft_memcpy(dst, src, len);
		dst[len] = '\0';
	}
	return (i);
}
