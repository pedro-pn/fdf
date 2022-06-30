/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:53:22 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/30 00:10:34 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate(int key, t_win_data *mlx_data)
{
	double	increment;

	increment = 0.261799;
	mlx_destroy_image(mlx_data->mlx, mlx_data->img.img);
	create_img(mlx_data);
	if (key == K_E)
		mlx_data->fdf.gamma += increment;
	if (key == K_Q)
		mlx_data->fdf.gamma -= increment;
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
	printf("%f\n", (cos(fdf.gamma)));
}