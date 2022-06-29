/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:50:22 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/29 20:26:19 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot(t_win_data mlx_data, t_fdf fdf)
{
	int x;
	int y;

	y = 0;
	while (y < fdf.num_rows)
	{
		x = 0;
		while (x < fdf.num_columns)
		{
			if (x + 1 < fdf.num_columns)
			{
				get_row_color(fdf, x, y, &mlx_data.img.color);
				bresen_alg(&mlx_data.img, get_bresendata(get_plot(x, y, fdf),
					get_plot(x+1, y, fdf)));
			}
			if (y + 1 < fdf.num_rows)
			{
				get_column_color(fdf, x, y, &mlx_data.img.color);
				bresen_alg(&mlx_data.img, get_bresendata(get_plot(x, y, fdf),
					get_plot(x, y + 1, fdf)));
			}
			x++;
		}
		y++;
	}
}

t_plot	get_plot(int x, int y, t_fdf fdf)
{
	t_plot p_set;

	p_set.x = x * fdf.tile_size;
	p_set.y = y * fdf.tile_size;
	p_set.z = fdf.matrix[y][x] * fdf.tile_size * fdf.z_factor;
	isometric(&p_set.x, &p_set.y, p_set.z);
	p_set.x += (SCREEN_WIDTH - MENU_WIDTH - fdf.num_columns * fdf.tile_size) / 2
			+ (fdf.num_rows * fdf.tile_size) / 2 + fdf.move_x * fdf.tile_size;
	p_set.y += (SCREEN_HEIGHT - fdf.num_rows * fdf.tile_size) / 2 + fdf.move_y
			* fdf.tile_size;
	return (p_set);
}

void	isometric(int *x, int *y, int z)
{
	int	previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(ISO_ANG);
	*y = -z + (previous_x + previous_y) * sin(ISO_ANG);
}
