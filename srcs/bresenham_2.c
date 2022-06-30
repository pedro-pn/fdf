/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:13:23 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/29 23:35:54 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_1(t_img *img, t_bresendata cord)
{
	int	p;

	if (cord.dx <= 0 && cord.dy <= 0)
		cord = fix_bresen(cord.xk, cord.yk, cord.x1, cord.y1);
	p = 2 * cord.dy - cord.dx;
	get_distance(cord, &(img->color));
	while (cord.x1 <= cord.xk)
	{
		my_mlx_pixel_put(img, cord.x1, cord.y1, get_color((*img).color, cord));
		cord.x1++;
		if (p < 0)
			p = p + 2 * cord.dy;
		else
		{
			p = p + 2 * cord.dy - 2 * cord.dx;
			cord.y1++;
		}
	}
}

void	draw_line_2(t_img *img, t_bresendata cord)
{
	int	p;

	if (cord.dx <= 0 && cord.dy <= 0)
		cord = fix_bresen(cord.yk, cord.xk, cord.y1, cord.x1);
	else
		cord = fix_bresen(cord.y1, cord.x1, cord.yk, cord.xk);
	p = 2 * cord.dy - cord.dx;
	get_distance(cord, &(img->color));
	while (cord.x1 <= cord.xk)
	{
		my_mlx_pixel_put(img, cord.y1, cord.x1, get_color((*img).color, cord));
		cord.x1++;
		if (p < 0)
			p = p + 2 * cord.dy;
		else
		{
			p = p + 2 * cord.dy - 2 * cord.dx;
			cord.y1++;
		}
	}
}

void	draw_line_3(t_img *img, t_bresendata cord)
{
	int	p;

	if (cord.dx <= 0 && cord.dy >= 0)
		cord = fix_bresen(cord.xk, -cord.yk, cord.x1, -cord.y1);
	else
		cord = fix_bresen(cord.x1, -cord.y1, cord.xk, -cord.yk);
	p = 2 * cord.dy - cord.dx;
	get_distance(cord, &(img->color));
	while (cord.x1 <= cord.xk)
	{
		my_mlx_pixel_put(img, cord.x1, -cord.y1, get_color((*img).color, cord));
		cord.x1++;
		if (p < 0)
			p = p + 2 * cord.dy;
		else
		{
			p = p + 2 * cord.dy - 2 * cord.dx;
			cord.y1++;
		}
	}
}

void	draw_line_4(t_img *img, t_bresendata cord)
{
	int	p;
	int	temp;

	temp = img->color.color;
	img->color.color = img->color.color_end;
	img->color.color_end = temp;
	if (cord.dx >= 0 && cord.dy <= 0)
		cord = fix_bresen(cord.yk, -cord.xk, cord.y1, -cord.x1);
	else
		cord = fix_bresen(cord.y1, -cord.x1, cord.yk, -cord.xk);
	p = 2 * cord.dy - cord.dx;
	get_distance(cord, &(img->color));
	while (cord.x1 <= cord.xk)
	{
		my_mlx_pixel_put(img, -cord.y1, cord.x1, get_color((*img).color, cord));
		cord.x1++;
		if (p < 0)
			p = p + 2 * cord.dy;
		else
		{
			p = p + 2 * cord.dy - 2 * cord.dx;
			cord.y1++;
		}
	}
}
