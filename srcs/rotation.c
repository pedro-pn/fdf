/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:53:22 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/30 13:23:18 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate(int key, t_win_data *mlx_data)
{
	double	increment;

	increment = 0.1;
	mlx_destroy_image(mlx_data->mlx, mlx_data->img.img);
	create_img(mlx_data);
	if (key == K_E)
		mlx_data->fdf.gamma += increment;
	if (key == K_Q)
		mlx_data->fdf.gamma -= increment;
	if (key == K_W)
		mlx_data->fdf.alpha += increment;
	if (key == K_S)
		mlx_data->fdf.alpha -= increment;
	if (key == K_A)
		mlx_data->fdf.beta -= increment;
	if (key == K_D)
		mlx_data->fdf.beta += increment;
	plot(*mlx_data, mlx_data->fdf);
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win,
		mlx_data->img.img, MENU_WIDTH, 0);
}

void	rotate_z(t_plot *p_set, t_fdf fdf)
{
	int	temp_x;
	int	temp_y;

	temp_x = p_set->x;
	temp_y = p_set->y;
	p_set->x = temp_x * cos(fdf.gamma) - temp_y * sin(fdf.gamma);
	p_set->y = temp_x * sin(fdf.gamma) + temp_y * cos(fdf.gamma);
}

void	rotate_x(t_plot *p_set, t_fdf fdf)
{
	int	temp_y;
	int	temp_z;

	temp_y = p_set->y;
	temp_z = p_set->z;
	p_set->y = temp_y * cos(fdf.alpha) - temp_z * sin(fdf.alpha);
	p_set->z = temp_y * sin(fdf.alpha) + temp_z * cos(fdf.alpha);
}

void	rotate_y(t_plot *p_set, t_fdf fdf)
{
	int	temp_x;
	int	temp_z;

	temp_x = p_set->x;
	temp_z = p_set->z;
	p_set->x = temp_x * cos(fdf.beta) + temp_z * sin(fdf.beta);
	p_set->z = -temp_x * sin(fdf.beta) + temp_z * cos(fdf.beta);
}
