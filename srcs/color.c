/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:18:53 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/29 14:30:42 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_matrix_color(t_fdf *fdf, char **row_splt, int row)
{
	int		column;
	char	*hexaptr;

	column = 0;
	fdf->matrix_color[row] = malloc(sizeof(int) * fdf->num_columns);
	while (row_splt[column])
	{
		hexaptr = ft_strchr(row_splt[column], ',');
		if (hexaptr)
			(fdf->matrix_color)[row][column] = htoi(hexaptr++);
		else
			(fdf->matrix_color)[row][column] = GRID_C;
		column++;
	}
}

void	get_row_color(t_fdf fdf, int x, int y, t_color *color)
{
	color->color = fdf.matrix_color[y][x];
	color->color_end = fdf.matrix_color[y][x + 1];
}

void	get_column_color(t_fdf fdf, int x, int y, t_color *color)
{
	color->color_end = fdf.matrix_color[y][x];
	color->color = fdf.matrix_color[y + 1][x];
}

void	paint_image(t_img *img)
{
	int	x;
	int	y;

	y = 0;
	while (y <= SCREEN_HEIGHT)
	{
		x = 0;
		while (x <= SCREEN_WIDTH)
		{
			my_mlx_pixel_put(img, x, y, SCREEN_C);
			x++;
		}
		y++;
	}
}

void	paint_menu(t_img *menu)
{
	int	x;
	int	y;

	y = 0;
	while (y <= SCREEN_HEIGHT)
	{
		x = 0;
		while (x <= 200)
		{
			my_mlx_pixel_put(menu, x, y, MENU_C);
			x++;
		}
		y++;
	}
}
