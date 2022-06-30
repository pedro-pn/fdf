/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:00:15 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/30 13:21:05 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exit_win(void *mlx_data)
{
	mlx_clear_window(((t_win_data *)mlx_data)->mlx,
		((t_win_data *)mlx_data)->mlx_win);
	mlx_destroy_image(((t_win_data *)mlx_data)->mlx,
		((t_win_data *)mlx_data)->img.img);
	mlx_destroy_image(((t_win_data *)mlx_data)->mlx,
		((t_win_data *)mlx_data)->menu.img);
	mlx_loop_end(((t_win_data *)mlx_data)->mlx);
	return (0);
}

int	key_handle(int key, void *mlx_data)
{
	if (key == K_ESC)
		exit_win(mlx_data);
	if (key == K_PLUS || key == K_MINUS)
		zoom(key, (t_win_data *)mlx_data);
	if (key == K_UP || key == K_DOWN || key == K_LEFT || key == K_RIGHT)
		move(key, (t_win_data *)mlx_data);
	if (key == K_COMMA || key == K_DOT)
		change_z(key, (t_win_data *)mlx_data);
	if (key == K_R)
		reset_position((t_win_data *)mlx_data);
	if (key == K_Q || key == K_E || key == K_W || key == K_S
		|| key == K_A || key == K_D)
		rotate(key, (t_win_data *)mlx_data);
	return (0);
}
