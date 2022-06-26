/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:18:53 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/26 12:38:24 by ppaulo-d         ###   ########.fr       */
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

static int get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

int	get_color(t_img img, t_bresendata cord)
{
    int red;
    int green;
    int blue;
	double percentage;
	
	percentage = get_percentage(cord, img, cord.x1);
    red = get_light((img.color >> 16) & 0xFF, (img.color_end >> 16) & 0xFF, percentage);
    green = get_light((img.color >> 8) & 0xFF, (img.color_end >> 8) & 0xFF, percentage);
    blue = get_light(img.color & 0xFF, img.color_end & 0xFF, percentage);
    return ((red << 16) | (green << 8) | blue);
}

double	get_distance(t_bresendata *cord)
{
	cord->x1_f = cord->x1;
	return (cord->xk - cord->x1);
}

double	get_percentage(t_bresendata cord, t_img img, int current)
{
	double	position;
	
	position = current - cord.x1_f;
	if (img.distance == 0)
	{
		return (1);
	}
	return (position / img.distance);
}
