/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:00:00 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/15 16:08:10 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mod_x(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

t_bresendata	get_bresendata(int x1, int y1, int xk, int yk)
{
	t_bresendata cord;

	cord.x1 = x1;
	cord.xk = xk;
	cord.y1 = y1;
	cord.yk = yk;
	cord.dx = xk - x1;
	cord.dy = yk - y1;
	return (cord);
}

void	bresen_alg(t_data *img, int x1, int y1, int xk, int yk)
{
	t_bresendata	cord;

	cord = get_bresendata(x1, y1, xk, yk);
	if (mod_x(xk - x1) > mod_x(yk - y1))
	{
		if ((xk - x1 > 0 && yk - y1 < 0) || (xk - x1 < 0 && yk - y1 > 0))
			draw_line_3(img, cord);
		// else if (xk - x1 < 0 && yk - y1 > 0)
		// 	draw_line_3(img, xk, -yk, x1, -y1);
		// else if (xk - x1 < 0 && yk - y1 < 0)
		// 	draw_line_1(img, xk, yk, x1, y1);
		else
			draw_line_1(img, cord);
	}
	else
	{
		if ((xk - x1 > 0 && yk - y1 < 0) || (xk - x1 < 0 && yk - y1 > 0))
			draw_line_4(img, cord);
		// else if (xk - x1 < 0 && yk - y1 > 0)
		// 	draw_line_4(img, cord);
		else if (xk - x1 < 0 && yk - y1 < 0)
			draw_line_2(img, xk, yk, x1, y1);
		else
			draw_line_2(img, x1, y1, xk, yk);
	}
}
