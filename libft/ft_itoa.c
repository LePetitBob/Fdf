/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 19:45:34 by vduriez           #+#    #+#             */
/*   Updated: 2020/09/03 11:13:05 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

long	ft_size(int n)
{
	int		size;
	int		signe;

	signe = (n < 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	size = 1;
	while (n > 9)
	{
		size++;
		n /= 10;
	}
	return (signe + size);
}

char	*ft_itoa(int n)
{
	int		size;
	int		signe;
	char	*res;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	signe = (n < 0) ? 1 : 0;
	size = ft_size(n);
	n = (n < 0) ? -n : n;
	if (!(res = malloc(sizeof(char) * size + 1)))
		return (NULL);
	res[size] = '\0';
	while (--size >= signe)
	{
		res[size] = (n % 10) + 48;
		n /= 10;
	}
	if (signe)
		res[0] = '-';
	return (res);
}
