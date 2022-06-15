/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:00:00 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/15 03:14:33 by ppaulo-d         ###   ########.fr       */
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

void	bren_alg(t_data *img, int x1, int y1, int xk, int yk)
{
	int dx;
	int dy;

	dx = xk - x1;
	dy = yk - y1;
	if (dx > dy)
	{
		if ((dx > 0 && dy < 0) || (dx < 0 && dy > 0))
		{
			if (mod_x(dy) > mod_x(dx))
				draw_line_4(img, -xk, yk, -x1, y1);
			else
				draw_line_3(img, x1, -y1, xk, -yk);
		}
		else if (dx < 0 && dy < 0)
			draw_line_2(img, xk, yk, x1, y1);
		else
			draw_line_1(img, x1, y1, xk, yk);
	}
	else if (dx < dy)
	{
		if ((dx > 0 && dy < 0) || (dx < 0 && dy > 0))
		{
			if (mod_x(dx) > mod_x (dy))
				draw_line_3(img, xk, -yk, x1, -y1);
			else
				draw_line_4(img, -x1, y1, -xk, yk);
		}
		else if (dx < 0 && dy < 0)
			draw_line_1(img, xk, yk, x1, y1);
		else
			draw_line_2(img, x1, y1, xk, yk);
	}
}