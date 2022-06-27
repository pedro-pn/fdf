/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:00:00 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/27 16:48:50 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bresendata	get_bresendata(int x1, int y1, int xk, int yk)
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
		if ((cord.dx > 0 && cord.dy < 0) || (cord.dx < 0 && cord.dy > 0))
			draw_line_3(img, cord);
		else
			draw_line_1(img, cord);
	}
	else
	{
		if ((cord.dx > 0 && cord.dy < 0) || (cord.dx < 0 && cord.dy > 0))
			draw_line_4(img, cord);
		else
			draw_line_2(img, cord);
	}
}
