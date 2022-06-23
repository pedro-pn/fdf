/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:16:36 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/22 22:19:11 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_img(t_win_data *mlx_data)
{
	mlx_data->img.img = mlx_new_image(mlx_data->mlx, SCREEN_WIDTH,
		SCREEN_LENGTH);
	mlx_data->img.addr = mlx_get_data_addr(mlx_data->img.img,
		&(mlx_data->img.bits_per_pixel), &(mlx_data->img.line_length),
		&(mlx_data->img.endian));
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data -> addr
		+ (y * data -> line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
