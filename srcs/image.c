/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:16:36 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/29 22:56:02 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_position(t_win_data *mlx_data)
{
	mlx_destroy_image(mlx_data->mlx, mlx_data->img.img);
	create_img(mlx_data);
	fdf_default(&mlx_data->fdf);
//	plot_iso(*mlx_data, mlx_data->fdf);
//	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win,
//		mlx_data->img.img, MENU_WIDTH, 0);
}

void	zoom(int key, t_win_data *mlx_data)
{
	int	increment;

	increment = 0;
	mlx_destroy_image(mlx_data->mlx,
		mlx_data->img.img);
	if (key == K_PLUS)
		increment = 2;
	else if (key == K_MINUS)
		increment = -2;
	create_img(mlx_data);
	if (mlx_data->fdf.tile_size > 1)
		mlx_data->fdf.tile_size += increment;
	if (mlx_data->fdf.tile_size <= 1)
		mlx_data->fdf.tile_size = 2;
//	get_start_pixels(&(mlx_data->fdf));
	plot(*mlx_data, mlx_data->fdf);
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win,
		mlx_data->img.img, MENU_WIDTH, 0);
}

void	move(int key, t_win_data *mlx_data)
{
	mlx_destroy_image(mlx_data->mlx, mlx_data->img.img);
	create_img(mlx_data);
	if (key == K_UP)
		mlx_data->fdf.move_y -= 10;
	else if (key == K_DOWN)
		mlx_data->fdf.move_y += 10;
	else if (key == K_LEFT)
		mlx_data->fdf.move_x -= 10;
	else if (key == K_RIGHT)
		mlx_data->fdf.move_x += 10;
	//get_start_pixels(&mlx_data->fdf);
	plot(*mlx_data, mlx_data->fdf);
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win,
		mlx_data->img.img, MENU_WIDTH, 0);
}

void	change_z(int key, t_win_data *mlx_data)
{
	float	increment;

	increment = 0;
	mlx_destroy_image(mlx_data->mlx, mlx_data->img.img);
	create_img(mlx_data);
	if (key == K_COMMA)
		increment = -0.1;
	if (key == K_DOT)
		increment = +0.1;
	mlx_data->fdf.z_factor += increment;
	plot(*mlx_data, mlx_data->fdf);
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win,
		mlx_data->img.img, MENU_WIDTH, 0);
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
