/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:15:52 by vduriez           #+#    #+#             */
/*   Updated: 2020/09/04 15:50:32 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	int		beg;
	int		end;

	if (!s1)
		return (NULL);
	end = ft_strlen(s1);
	beg = 0;
	while (ft_check(s1[beg], set))
		beg++;
	if (beg == end)
	{
		str = malloc(1);
		str[0] = '\0';
		return (str);
	}
	while (ft_check(s1[end - 1], set))
		end--;
	str = ft_substr(s1, beg, (end - beg));
	return (str);
}
