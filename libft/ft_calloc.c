/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 19:27:10 by vduriez           #+#    #+#             */
/*   Updated: 2020/08/20 20:52:08 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*dest;
	int		i;

	i = size * count;
	if (!(dest = malloc(i)))
		return (NULL);
	while (i > 0)
	{
		dest[i - 1] = 0;
		i--;
	}
	return ((void *)dest);
}
