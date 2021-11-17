/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 15:49:35 by vduriez           #+#    #+#             */
/*   Updated: 2020/08/25 18:30:41 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int a;

	if (n < 0)
	{
		a = -n;
		ft_putchar_fd('-', fd);
	}
	else
		a = n;
	if (a > 9)
		ft_putnbr_fd(a / 10, fd);
	ft_putchar_fd((a % 10) + 48, fd);
}
