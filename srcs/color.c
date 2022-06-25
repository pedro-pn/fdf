/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:18:53 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/25 16:34:04 by ppaulo-d         ###   ########.fr       */
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
			(fdf->matrix_color)[row][column] = 0X00FFFFFF;
		column++;
	}
}

void	get_row_color(t_fdf fdf, t_iso iso, t_img *img)
{
	img->color = fdf.matrix_color[iso.row][iso.column];
	img->color_end = fdf.matrix_color[iso.row][iso.column + 1];
}

void	get_column_color(t_fdf fdf, t_iso iso, t_img *img)
{
	img->color_end = fdf.matrix_color[iso.row][iso.column];
	img->color = fdf.matrix_color[iso.row + 1][iso.column];
}

void	color(t_bresendata cord, t_img *img)
{
	int distance;
	double	color_gap;
	
	distance = cord.xk - cord.x1 + 1;
	if (distance < 0)
		distance *= -1;
	color_gap = img->color_end - img->color;
	img->color_factor = (color_gap) / (distance);
}