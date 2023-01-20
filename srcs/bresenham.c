/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:00:00 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/20 16:49:37 by ppaulo-d         ###   ########.fr       */
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
	cord.dx = abs(pk.x - p1.x);
	cord.dy = -abs(pk.y - p1.y);
	cord.increment_x = 1;
	cord.increment_y = 1;
	if (cord.x1 >= cord.xk)
		cord.increment_x = -1;
	if (cord.y1 >= cord.yk)
		cord.increment_y = -1;
	return (cord);
}

void	bresen_alg(t_img *img, t_bresendata cord)
{
	int	error;

	error = cord.dx + cord.dy;
	set_color_params(&img->color, cord);
	while (TRUE)
	{
		my_mlx_pixel_put(img, cord.x1, cord.y1, get_color((*img).color, cord));
		if (cord.x1 == cord.xk && cord.y1 == cord.yk)
			break ;
		if (2 * error >= cord.dy)
		{
			if (cord.x1 == cord.xk)
				break ;
			error = error + cord.dy;
			cord.x1 = cord.x1 + cord.increment_x;
		}
		if (2 * error <= cord.dx)
		{
			if (cord.y1 == cord.yk)
				break ;
			error = error + cord.dx;
			cord.y1 = cord.y1 + cord.increment_y;
		}
	}
}
