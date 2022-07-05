/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:16:36 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/07/05 17:37:18 by ppaulo-d         ###   ########.fr       */
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
	if (key == K_PLUS || key == MS_UP)
		increment = 2;
	else if (key == K_MINUS || key == MS_DOWN)
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
	if (key == K_COMMA || key == MS_DOWN)
		increment = -0.1;
	if (key == K_DOT || key == MS_UP)
		increment = +0.1;
	mlx_data->fdf.z_factor += increment;
	reproject(mlx_data);
}

int	reproject(void *mlx_data)
{
	t_win_data	*mlx;

	mlx = (t_win_data *)mlx_data;
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_image(mlx->mlx, mlx->menu.img);
	create_menu(mlx);
	create_img(mlx);
	plot(*mlx, mlx->fdf);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
		mlx->img.img, MENU_WIDTH, 0);
	return (0);
}
