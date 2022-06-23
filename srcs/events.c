/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:00:15 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/23 12:00:39 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	//ft_printf("key: %d\n", key);
	if (key == K_ESC)
		exit_win(mlx_data);
	if (key == K_PLUS)
		zoom(key, (t_win_data *)mlx_data);
	if (key == K_MINUS)
		zoom(key, (t_win_data *)mlx_data);
	if (key == K_UP)
		move(key, (t_win_data *)mlx_data);
	if (key == K_DOWN)
		move(key, (t_win_data *)mlx_data);
	if (key == K_LEFT)
		move(key, (t_win_data *)mlx_data);
	if (key == K_RIGHT)
		move(key, (t_win_data *)mlx_data);
	return (0);
}
