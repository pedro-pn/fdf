/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:16:36 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/30 19:18:41 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_position(t_win_data *mlx_data)
{
	fdf_default(&mlx_data->fdf);
	reproject(mlx_data);
}

void	zoom(int key, t_win_data *mlx_data)
{
	int	increment;

	increment = 0;
	if (key == K_PLUS)
		increment = 2;
	else if (key == K_MINUS)
		increment = -2;
	if (mlx_data->fdf.tile_size > 1)
		mlx_data->fdf.tile_size += increment;
	if (mlx_data->fdf.tile_size <= 1)
		mlx_data->fdf.tile_size = 2;
	reproject(mlx_data);
}

void	move(int key, t_win_data *mlx_data)
{
	if (key == K_UP)
		mlx_data->fdf.move_y -= 10;
	else if (key == K_DOWN)
		mlx_data->fdf.move_y += 10;
	else if (key == K_LEFT)
		mlx_data->fdf.move_x -= 10;
	else if (key == K_RIGHT)
		mlx_data->fdf.move_x += 10;
	reproject(mlx_data);
}

void	change_z(int key, t_win_data *mlx_data)
{
	float	increment;

	increment = 0;
	if (key == K_COMMA)
		increment = -0.1;
	if (key == K_DOT)
		increment = +0.1;
	mlx_data->fdf.z_factor += increment;
	reproject(mlx_data);
}

void	reproject(t_win_data *mlx_data)
{
	mlx_destroy_image(mlx_data->mlx, mlx_data->img.img);
	create_img(mlx_data);
	plot(*mlx_data, mlx_data->fdf);
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win,
		mlx_data->img.img, MENU_WIDTH, 0);
}
