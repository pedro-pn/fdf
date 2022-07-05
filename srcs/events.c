/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:00:15 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/07/05 18:00:16 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	event_hook(t_win_data *mlx_data)
{
	mlx_hook(mlx_data->mlx_win, 4, 1L << 2, &mouse_press, mlx_data);
	mlx_hook(mlx_data->mlx_win, 5, 1L << 3, &mouse_release, mlx_data);
	mlx_hook(mlx_data->mlx_win, 6, 1L << 6, &mouse_move, mlx_data);
	mlx_hook(mlx_data->mlx_win, 17, 0, &exit_win, mlx_data);
	mlx_hook(mlx_data->mlx_win, 2, 1L << 0, &key_press, mlx_data);
	mlx_expose_hook(mlx_data->mlx_win, &redraw, mlx_data);
	mlx_key_hook(mlx_data->mlx_win, &key_release, mlx_data);
}

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

int	key_release(int key, void *mlx_data)
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
	if (key == K_O || key == K_I)
		projection_type(key, (t_win_data *)mlx_data);
	if (key == K_SHIFT)
		((t_win_data *)mlx_data)->mouse.shift = FALSE;
	return (0);
}

int	key_press(int key, void *mlx_data)
{
	if (key == K_SHIFT)
		((t_win_data *)mlx_data)->mouse.shift = TRUE;
	return (0);
}

int	redraw(void *mlx_data)
{
	reproject(mlx_data);
	reproject_menu(mlx_data);
	return (0);
}
