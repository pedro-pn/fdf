/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:00:00 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/30 13:20:32 by ppaulo-d         ###   ########.fr       */
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
	if (mod(cord.dx) > mod(cord.dy))
	{
		if ((cord.dx >= 0 && cord.dy <= 0) || (cord.dx <= 0 && cord.dy >= 0))
			draw_line_3(img, cord);
		else
			draw_line_1(img, cord);
	}
	else
	{
		if ((cord.dx >= 0 && cord.dy <= 0) || (cord.dx <= 0 && cord.dy >= 0))
			draw_line_4(img, cord);
		else
			draw_line_2(img, cord);
	}
}
