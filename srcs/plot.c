/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:50:22 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/21 19:41:36 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	start_iso(t_iso *iso, t_fdf fdf)
{
	iso->y = fdf.start_y + round(fdf.tile_size * tan(0.463646716));
	iso->x = fdf.start_x - fdf.tile_size;
	iso->first_x = 0;
	iso->first_y = 0;
	iso->row = 0;
	iso->column = 0;
}

void	draw_iso(t_win_data mlx_data, t_fdf fdf, t_iso *iso)
{
	t_bresendata	cord;

	iso->xk = iso->x + (fdf.tile_size);
	iso->yk = iso->y + (round(fdf.tile_size * tan(0.463646716)))
		+ (fdf.matrix[iso->row][iso->column]
			- fdf.matrix[iso->row][iso->column + 1]);
	cord = get_bresendata(iso->x, iso->y, iso->xk, iso->yk);
	mlx_data.img.color = get_color(*iso, fdf.map);
	bresen_alg(&(mlx_data.img), cord);
	plot_columns_iso(mlx_data, fdf, iso);
	iso->column++;
	iso->y = iso->yk;
	iso->x = iso->xk;
}

void	plot_iso(t_win_data mlx_data, t_fdf fdf)
{
	t_iso	iso;

	start_iso(&iso, fdf);
	while (iso.row < fdf.num_rows)
	{
		iso.column = 0;
		if (iso.row != 0)
		{
			iso.y = iso.first_y;
			iso.x = iso.first_x;
		}
		while (iso.column < fdf.num_columns - 1)
			draw_iso(mlx_data, fdf, &iso);
		iso.row++;
	}
}

void	get_start_pixels(t_fdf *fdf)
{
	(*fdf).start_x = (SCREEN_WIDTH / 2) - ((((*fdf).num_columns
					* (*fdf).tile_size)
				- ((*fdf).num_rows * fdf->tile_size)) / 2);
	(*fdf).start_y = (SCREEN_LENGTH / 2)
		- ((((*fdf).num_columns * round(fdf->tile_size * tan(0.463646716)))
				+ ((*fdf).num_rows * round(fdf->tile_size
						* tan(0.463646716)))) / 2);
}

void	plot_columns_iso(t_win_data mlx_data, t_fdf fdf, t_iso *iso)
{
	int	nxk;
	int	nyk;
	int	column;

	column = iso->column;
	if (iso->row < fdf.num_rows - 1)
	{
		nxk = iso->x - (fdf.tile_size);
		nyk = iso->y + (round(fdf.tile_size * tan(0.463646716)))
			+ (fdf.matrix[iso->row][iso->column]
				- fdf.matrix[iso->row + 1][iso->column]);
		bresen_alg(&(mlx_data.img), get_bresendata(iso->x, iso->y, nxk, nyk));
		if (iso->column == 0)
		{
			iso->first_y = nyk;
			iso->first_x = nxk;
		}
		column++;
		nxk = iso->xk - (fdf.tile_size);
		nyk = iso->yk + (round(fdf.tile_size * tan(0.463646716)))
			+ (fdf.matrix[iso->row][column] - fdf.matrix[iso->row + 1][column]);
		bresen_alg(&(mlx_data.img), get_bresendata(iso->xk, iso->yk, nxk, nyk));
	}
}
