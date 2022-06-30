/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:00:00 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/30 00:05:05 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bresendata	get_bresendata(t_plot p1, t_plot pk) // alterar chamadas em bresenalg_2
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
	if (cord.dx == 0)
		draw_line_dx(img, cord);
	else if (cord.dy == 0)
		draw_line_dy(img, cord);
	else if (mod(cord.dx) > mod(cord.dy))
	{
		if ((cord.dx > 0 && cord.dy < 0) || (cord.dx < 0 && cord.dy > 0))
			draw_line_3(img, cord);
		else
			draw_line_1(img, cord);
	}
	else if (mod(cord.dx) < mod(cord.dy))
	{
		if ((cord.dx > 0 && cord.dy < 0) || (cord.dx < 0 && cord.dy > 0))
			draw_line_4(img, cord);
		else
			draw_line_2(img, cord);
	}
}

void	draw_line_dy(t_img *img, t_bresendata cord)
{
	if (cord.xk < cord.x1)
		cord = fix_bresen(cord.xk, cord.y1, cord.x1, cord.yk);
	get_distance(cord, &(img->color));
	while (cord.x1 <= cord.xk)
	{
		//ft_printf("dy constante: x: %d\t y: %d\n", cord.x1, cord.y1);
	//	my_mlx_pixel_put(img, cord.x1, cord.y1, get_color((*img).color, cord));
		cord.x1++;
	}
}

void	draw_line_dx(t_img *img, t_bresendata cord)
{
	if (cord.yk < cord.y1)
		cord = fix_bresen(cord.x1, cord.yk, cord.xk, cord.y1);
	get_distance(cord, &(img->color));
	while (cord.y1 <= cord.yk)
	{
		//ft_printf("dx constante: x: %d\t y: %d\n", cord.x1, cord.y1);
		//my_mlx_pixel_put(img, cord.x1, cord.y1, get_color((*img).color, cord));
		cord.y1++;
	}
}