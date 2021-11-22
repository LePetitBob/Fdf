/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:25:56 by vduriez           #+#    #+#             */
/*   Updated: 2021/11/22 02:45:45 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
#include "mlx.h"
#include <math.h>


/* quadrillage de pixels  */

	/* while (var->x < 1550)
		{
		while (var->y < 806)
		{
		mlx_pixel_put(var->mlx, var->win, var->x, var->y, 0x00FF0000);
		var->y += 25;
		}
		if (var->y >= 806)
		{
			var->y = 150;
			var->x += 150;
		}
	}*/
/* quadrillage de strings  */

	/* while (var->x < 1550)
		{
		while (var->y < 806)
		{
		mlx_string_put(var->mlx, var->win, var->x, var->y, 0x00FF0000, "Ouech les boloss");
		var->y += 25;
		}
		if (var->y >= 806)
		{
			var->y = 150;
			var->x += 150;
		}
	}*/

typedef struct	s_vars {
	void			*mlx;
	void			*win;
	int				fd;
	int				**map;
	int				mapx;
	int				mapy;
    int     		x;
    int     		y;
	int				z;
	int				xmap;
	int				ymap;
	int				zmap;
    int     		x1;
    int     		y1;
	int				z1;
    int     		x2;
    int     		y2;
	int				z2;
	unsigned int	color;
}				t_vars;

char	*ft_strntndup(const char *s1, int index, int n)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (s1[index + i] && i < n)
		i++;
	if (!(res = malloc(sizeof(char) * i + 1)))
		return (NULL);
	while (j < i)
	{
		res[j] = s1[j + index];
		j++;
	}
	res[j] = '\0';
	return (res);
}

int	ft_atoi(const char *str)
{
	int i;
	int signe;
	int somme;

	i = 0;
	signe = 1;
	somme = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		signe = -1;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		somme = 10 * somme + (str[i] - 48);
		i++;
	}
	return (somme * signe);
}

void draw_lineR (int x0, int y0, int dx, int dy, t_vars *var)
{
	int		i;
	float	m;
	i = 0;
	//var = get_map_limits(var);
	m = ((float) dy / ((float) dx));
	while (++i < dx)
		mlx_pixel_put(var->mlx, var->win, x0 + i, (y0 + m * i), 0x00FF0000);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void draw_segment(t_vars *var)
{
	float	a=0;
	int		temp=0;
	int		cste=0;
	int		dy;
	int		dx;

	dx=abs(var->x2 - var->x1);
	dy=abs(var->y2 - var->y1);
	if(dx>=dy && dx!=0 && dy!=0)
	{      
   if(var->x1>var->x2)
   {
      temp=var->x1;
      var->x1=var->x2;
      var->x2=temp;
   
      temp=var->y1;
      var->y1=var->y2;
      var->y2=temp;
	}
	a=((float)(var->y2-var->y1)/(var->x2-var->x1));  
	for(int x=0; x < dx + 1;x++)
		mlx_pixel_put(var->mlx, var->win, x+var->x1, var->y1+(x*a)+cste, var->color);
	}
	if(dx<dy && dx!=0 && dy!=0)
	{
		if(var->y1>var->y2)
		{
			temp=var->y1;
			var->y1=var->y2;
			var->y2=temp;	
			temp=var->x1;
			var->x1=var->x2;
			var->x2=temp;
		}
		a=((float)(var->x2-var->x1)/(var->y2-var->y1));
		for(int y=0;abs(y)<dy+1;y++)
			mlx_pixel_put(var->mlx, var->win, var->x1+(y*a)+cste, var->y1 + y, var->color);
	}
	if(dx==0)
	{
	if(var->y1>var->y2)
	{
		temp=var->y1;
		var->y1=var->y2;
		var->y2=temp;
	}
	for(int y=var->y1;y<var->y2+1;y++)
			mlx_pixel_put(var->mlx, var->win, var->x1, y, var->color);
	}
	if(dy==0)
	{
		if(var->x1>var->x2)
		{
			temp=var->x1;
			var->x1=var->x2;
			var->x2=temp;
		}
		for(int x=var->x1;x<var->x2+1;x++)
			mlx_pixel_put(var->mlx, var->win, x, var->y1, var->color);
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_lineB (int x0, int y0, int dx, int dy, t_vars *var)
{
	int		i;
	float	m;
	i = 0;
	//var = get_map_limits(var);
	m = ((float) dy / ((float) dx));
	while (++i < dx)
		mlx_pixel_put(var->mlx, var->win, x0 + i, (y0 + m * i), 0x000000FF);
}

void draw_lineG (int x0, int y0, int dx, int dy, t_vars *var)
{
	int		i;
	float	m;
	i = 0;
	//var = get_map_limits(var);
	m = ((float) dy / ((float) dx));
	while (++i < dx)
		mlx_pixel_put(var->mlx, var->win, x0 + i, (y0 + m * i), 0x0000FF00);
}

void	free_map(t_vars *var)
{
	int	i;

	i = 0;
	while (i < var->mapy)
	{
		free(var->map[i]);
		i++;
	}
	free(var->map);
}

int	ft_exit(t_vars *var)
{
	mlx_destroy_window(var->mlx, var->win);
	mlx_destroy_display(var->mlx);
	free(var->mlx);
	free_map(var);
	close(var->fd);
	exit(1);
}

int	ft_exit_close(t_vars *var)
{
	free(var->mlx);
	close(var->fd);
	exit(1);
}

void	draw_line(int x1, int y1, int x2, int y2, t_vars *var)
{
	var->x1 = x1;
	var->x2 = x2;
	var->y1 = y1;
	var->y2 = y2;
	draw_segment(var);
}

int	ft_get_nbr(char *line, int	i)
{
	int		res;
	char	*nb;

	res = 0;
	while (line[i] >= 48 && line[i] <= 57)
	{
		res++;
		i++;
	}
	nb = ft_strntndup(line, i, res);
	res = ft_atoi(nb);
	free(nb);
	printf("%d ", res);
	return (res);
}

int	ft_skip_nbr(char *line, int i)
{
	while (line[i] >= 48 && line[i] <= 57)
		i++;
	return (i);
}

void	get_map(t_vars *var, char **av)
{
	char	*line;
	int		i;
	int		j;
	int		k;

	i = 0;
	var->map = malloc(sizeof(int *) * (var->mapy));
	if (!var->map)
		return ;
	var->fd = open(av[1], O_RDONLY);
	line = get_next_line(var->fd);
	while (line)
	{
		k = 0;
		j = 0;
		while (line[j])
		{
			var->map[i] = malloc(sizeof(int) * (var->mapx));
			if (!var->map[i])
				return ;/////////////////////////////////free le reste aussi
			if (line[j] >= 48 && line[j] <= 57)
			{
				var->map[i][k] = ft_get_nbr(line, j);
				j = ft_skip_nbr(line, j);
				k++;
			}
			else
				j++;
		}
		i++;
		free(line);
		line = get_next_line(var->fd);
	}
	free(line);
	close(var->fd);
}

void	check_map(t_vars *var)
{
	int		i;
	char	*line;

	var->mapx = 0;
	line = get_next_line(var->fd);
	i = 0;
	while (line[i])
	{
		if (line[i + 1] && line[i] != 32 && (line[i + 1] == 32
			||  line[i + 1] == '\n'))
			var->mapx++;
		i++;
	}
	while (line)
	{
		var->mapy++;
		free(line);
		line = get_next_line(var->fd);
	}
	free(line);
	close(var->fd);
}

void	ft_draw_map(t_vars *var)
{
	int i = 0;
	int j = 0;
	while (i < var->mapy)
	{
		j = 0;
		while (j < var->mapx)
		{
			printf("%d ", var->map[i][j]);
			if (var->map[i][j] < 10)
				printf(" ");
			j++;
		}
		printf("\n");
		i++;
	}
}

int	key_hook(int keycode, t_vars *var)
{
	if (keycode == 65307)
		ft_exit(var);
	//draw_lineR(150, 250, 100, 33, var);
	//draw_lineB(150, 250, 33, -100, var);
	//draw_lineG(150, 250, 100, 200, var);
	var->color = 0x00FFFF00;				//yellow
	draw_line(500, 500, 600, 500, var); 	//sq
	draw_line(500, 500, 500, 600, var); 	//	ua
	draw_line(600, 600, 500, 600, var); 	//	  re
	draw_line(600, 600, 600, 500, var); 	//:)
	return (0);
}

int main(int ac, char **av)
{
    t_vars  var;

	(void)ac;
	(void)av;

    var.mlx = mlx_init();
	var.fd = open(av[1], O_RDONLY);
	if (var.fd == -1)
		ft_exit_close(&var);
	check_map(&var);
	printf("mapx %d   mapy%d\n\n", var.mapx, var.mapy);
	get_map(&var, av);
	ft_draw_map(&var);
    var.win = mlx_new_window(var.mlx, 1700, 956, "merde alors");
	mlx_key_hook(var.win, key_hook, &var);
	mlx_hook(var.win, 17, 1L << 17, ft_exit, &var);
    mlx_loop(var.mlx);
    return (0);
}
