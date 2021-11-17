/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:25:56 by vduriez           #+#    #+#             */
/*   Updated: 2021/11/17 14:55:39 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "minilibx/mlx.h"


typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	exit_hook(void)
{
	exit(1);
}

int	key_hook(int keycode, t_vars *var)
{
    (void)var;
	printf("%d\n", keycode);
    mlx_string_put(var->mlx, var->win, 150, 150, 0x00FFFFFF, "Ouech les boloss");
	return (0);
}

int main()
{
    t_vars  var;

    var.mlx = mlx_init();
    var.win = mlx_new_window(var.mlx, 2560, 1400, "merde alors");
	mlx_key_hook(var.win, key_hook, &var);
	mlx_hook(var.win, 17, 1L << 17, exit_hook, &var);
    (void)var.win;
    mlx_loop(var.mlx);
    return (0);
}
