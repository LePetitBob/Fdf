/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:10:08 by vduriez           #+#    #+#             */
/*   Updated: 2021/11/12 16:47:22 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[start + j])
		j++;
	j = (len > j) ? j : len;
	if (start >= (unsigned int)ft_strlen(s))
		j = 0;
	if (!(res = malloc(sizeof(char) * (j + 1))))
		return (NULL);
	while (s[start + i] && i < j)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
