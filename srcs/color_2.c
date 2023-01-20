/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:16:41 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/20 16:28:15 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_light(int color, int color_end, double percentage)
{
	return ((int)((1 - percentage) * color + percentage * color_end));
}

static double	get_percentage(t_color color, int current)
{
	double	position;

	position = abs(current - color.start_point);
	if (color.distance == 0)
		return (1);
	return (position / color.distance);
}

int	get_color(t_color color, t_bresendata cord)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	percentage = get_percentage(color, cord.x1);
	red = get_light((color.color >> 16) & 0xFF,
			(color.color_end >> 16) & 0xFF, percentage);
	green = get_light((color.color >> 8) & 0xFF,
			(color.color_end >> 8) & 0xFF, percentage);
	blue = get_light(color.color & 0xFF,
			color.color_end & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

void	set_color_params(t_color *color, t_bresendata cord)
{
	color->distance = cord.dx;
	color->start_point = cord.x1;
}
