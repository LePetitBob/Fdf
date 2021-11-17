/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:37:23 by vduriez           #+#    #+#             */
/*   Updated: 2020/08/27 21:49:15 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst2;
	const unsigned char	*src2;

	if (!dst && !src)
		return (0);
	src2 = (unsigned char*)src;
	dst2 = (unsigned char*)dst;
	if (src2 < dst2)
		while (len--)
			dst2[len] = src2[len];
	else
	{
		while (len--)
			*(dst2++) = *(src2++);
	}
	return (dst);
}
