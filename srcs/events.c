/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:00:15 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/22 22:26:39 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"

int	exit_win(void *mlx_data)
{
	mlx_clear_window(((t_win_data *)mlx_data)->mlx,
		((t_win_data *)mlx_data)->mlx_win);
	mlx_destroy_image(((t_win_data *)mlx_data)->mlx,
		((t_win_data *)mlx_data)->img.img);
	mlx_loop_end(((t_win_data *)mlx_data)->mlx);
	return (0);
}

int	key_handle(int key, void *mlx_data)
{
	ft_printf("key: %d\n", key);
	if (key == ESC)
		exit_win(mlx_data);
	if (key == 48)
	{
		mlx_destroy_image(((t_win_data *)mlx_data)->mlx,
		((t_win_data *)mlx_data)->img.img);
		create_img(mlx_data);
		my_mlx_pixel_put(&((t_win_data *) mlx_data)->img, 5, 5, 0X00FF0000);
		mlx_put_image_to_window(((t_win_data *) mlx_data)->mlx, ((t_win_data *) mlx_data)->mlx_win,
			((t_win_data *) mlx_data)->img.img, 0, 0);
	}
	return (0);
}