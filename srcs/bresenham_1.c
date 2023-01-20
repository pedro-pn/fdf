/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:00:00 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/20 14:55:50 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bresendata	get_bresendata(t_plot p1, t_plot pk)
{
	t_bresendata	cord;

	cord.x1 = p1.x;
	cord.xk = pk.x;
	cord.y1 = p1.y;
	cord.yk = pk.y;
	cord.dx = pk.x - p1.x;
	cord.dy = pk.y - p1.y;
	return (cord);
}

t_bresendata	fix_bresen(int x1, int y1, int xk, int yk)
{
	t_bresendata	cord;

	cord.x1 = x1;
	cord.xk = xk;
	cord.y1 = y1;
	cord.yk = yk;
	cord.dx = xk - x1;
	cord.dy = yk - y1;
	return (cord);
}

void	bresen_alg(t_img *img, t_bresendata cord)
{
	int sx;
	int	sy;
	int	error;
	int	e2;

	cord.dx = abs(cord.xk - cord.x1);
	cord.dy = -abs(cord.yk - cord.y1);
	if (cord.x1 < cord.xk)
		sx = 1;
	else
		sx = -1;
	if (cord.y1 < cord.yk)
		sy = 1;
	else
		sy = -1;
	error = cord.dx + cord.dy;
	img->color.distance = cord.dx;
	img->color.start_point = cord.x1;
	while (TRUE)
	{
		my_mlx_pixel_put(img, cord.x1, cord.y1, get_color((*img).color, cord));
		if (cord.x1 == cord.xk && cord.y1 == cord.yk)
			break ;
		e2 = 2 * error;
		if (e2 >= cord.dy)
		{
			if (cord.x1 == cord.xk)
				break;
			error = error + cord.dy;
			cord.x1 = cord.x1 + sx;
		}
		if (e2 <= cord.dx)
		{
			if (cord.y1 == cord.yk)
				break;
			error = error + cord.dx;
			cord.y1 = cord.y1 + sy;
		}
	}
}
