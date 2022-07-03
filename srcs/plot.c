/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:50:22 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/07/03 13:35:10 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot(t_win_data mlx_data, t_fdf fdf)
{
	int	x;
	int	y;

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
						get_plot(x + 1, y, fdf)));
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
	t_plot	p_set;

	p_set.x = x * fdf.tile_size;
	p_set.y = y * fdf.tile_size;
	p_set.z = fdf.matrix[y][x] * fdf.tile_size * fdf.z_factor;
	p_set.x -= (fdf.num_columns * fdf.tile_size) / 2;
	p_set.y -= (fdf.num_rows * fdf.tile_size) / 2;
	rotate_x(&p_set, fdf);
	rotate_y(&p_set, fdf);
	rotate_z(&p_set, fdf);
	if (fdf.projection == ISOMETRIC)
		isometric(&p_set.x, &p_set.y, p_set.z);
	p_set.x += (SCREEN_WIDTH - MENU_WIDTH) / 2 + fdf.move_x;
	p_set.y += (SCREEN_HEIGHT / 2) + fdf.move_y;
	return (p_set);
}

void	isometric(int *x, int *y, int z)
{
	int	temp_x;
	int	temp_y;

	temp_x = *x;
	temp_y = *y;
	*x = (temp_x - temp_y) * cos(ISO_ANG);
	*y = -z + (temp_x + temp_y) * sin(ISO_ANG);
}

void	projection_type(int key, t_win_data *mlx_data)
{
	if (key == K_O)
		mlx_data->fdf.projection = ORTHOGRAPHIC;
	if (key == K_I)
		mlx_data->fdf.projection = ISOMETRIC;
	reproject(mlx_data);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (x < SCREEN_WIDTH - MENU_WIDTH && x >= 0 && y <= SCREEN_HEIGHT && y >= 0)
	{
		dst = data -> addr
			+ (y * data -> line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
