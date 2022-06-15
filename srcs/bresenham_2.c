/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:13:23 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/15 03:13:35 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_1(t_data *img, int x1, int y1, int xk, int yk)
{
	int x;
	int y;
	int dx;
	int dy;
	int p;

	x = x1;
	y = y1;
	dx = xk - x1;
	dy = yk - y1;
	p = 2 * dy - dx;
	while (x <= xk)
	{
		my_mlx_pixel_put(img, x, y, 0X00FF0000);
		ft_printf("%d\t%d\n", x, y);
		x++;
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			p = p + 2 * dy - 2 * dx;
			y++;
		}
	}
}


void	draw_line_2(t_data *img, int x1, int y1, int xk, int yk)
{
	int x;
	int y;
	int dx;
	int dy;
	int p;

	x = y1;
	y = x1;
	dx = yk - y1;
	dy = xk - x1;
	p = 2 * dy - dx;
	while (x <= yk)
	{
		my_mlx_pixel_put(img, y, x, 0X00FF0000);
		ft_printf("%d\t%d\n", x, y);
		x++;
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			p = p + 2 * dy - 2 * dx;
			y++;
		}
	}
}

void	draw_line_3(t_data *img, int x1, int y1, int xk, int yk)
{
	int x;
	int y;
	int dx;
	int dy;
	int p;

	x = x1;
	y = y1;
	dx = xk - x1;
	dy = yk - y1;
	p = 2 * dy - dx;
	while (x <= xk)
	{
		my_mlx_pixel_put(img, x, -y, 0X00FF0000);
		ft_printf("%d\t%d\n", x, y);
		x++;
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			p = p + 2 * dy - 2 * dx;
			y++;
		}
	}
}

void	draw_line_4(t_data *img, int x1, int y1, int xk, int yk)
{
	int x;
	int y;
	int dx;
	int dy;
	int p;

	x = y1;
	y = x1;
	dx = yk - y1;
	dy = xk - x1;
	p = 2 * dy - dx;
	while (x <= yk)
	{
		my_mlx_pixel_put(img, -y, x, 0X00FF0000);
		ft_printf("%d\t%d\n", x, y);
		x++;
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			p = p + 2 * dy - 2 * dx;
			y++;
		}
	}
}
