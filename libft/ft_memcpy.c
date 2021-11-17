/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:51:24 by vduriez           #+#    #+#             */
/*   Updated: 2020/08/26 17:25:08 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			count;
	unsigned char	*src2;
	unsigned char	*dst2;

	if (!dst && !src)
		return (0);
	src2 = (unsigned char *)src;
	dst2 = (unsigned char *)dst;
	count = 0;
	while (count < n && n >= 1)
	{
		dst2[count] = src2[count];
		count++;
	}
	return (dst);
}
