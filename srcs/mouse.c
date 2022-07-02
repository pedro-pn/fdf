/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:36:47 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/07/02 17:53:37 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	print_oi(int button, int key, int key2, void *param);

void	mouse_hook(t_win_data *mlx_data)
{
	mlx_hook(mlx_data->mlx_win, 4, 1L<<2, &mouse_press, mlx_data);
	mlx_hook(mlx_data->mlx_win, 5, 1L<<3, &mouse_release, mlx_data);
	mlx_hook(mlx_data->mlx_win, 6, 1L<<6, &mouse_rotate, mlx_data);
}

int	mouse_press(int button, int x, int y, void *mlx_data)
{
	t_win_data	*mlx;

	mlx = (t_win_data *)mlx_data;
	mlx->mouse.x = x;
	mlx->mouse.y = y;
	mlx->mouse.button = button;
	if (x > MENU_WIDTH && x < SCREEN_WIDTH && y > 0 && y < SCREEN_HEIGHT
			&& button == MB_LEFT)
		mlx->mouse.is_pressed = TRUE;
	if ((button == MS_UP || button == MS_DOWN) &&mlx->mouse.shift == TRUE)
		change_z(button, mlx);
	if ((button == MS_UP || button == MS_DOWN) &&mlx->mouse.shift == FALSE)
		zoom(button, mlx);
	return (0);
	
}

int	mouse_release(int button, int x, int y, void *mlx_data)
{
	t_win_data	*mlx;
	
	mlx = (t_win_data *)mlx_data;
	if (mlx->mouse.is_pressed == TRUE && mlx->mouse.button == button)
	{
		mlx->mouse.is_pressed = FALSE;
		mlx->mouse.x = x;
		mlx->mouse.y = y;
	}
	return (0);
}

int	mouse_rotate(int x, int y, void *mlx_data)
{
	t_win_data *mlx;
	double	increment_y;
	double	increment_x;

	mlx = (t_win_data *)mlx_data;
	if (mlx->mouse.is_pressed == TRUE && mlx->mouse.button == MB_LEFT)
	{
		increment_y = (mlx->mouse.y - y) * 0.005;
		increment_x = (mlx->mouse.x - x) * 0.005;
		mlx->fdf.alpha += increment_y;
		mlx->fdf.beta -= increment_x;
		reproject(mlx);
		mlx->mouse.x = x;
		mlx->mouse.y = y;
	}
	
	return 0;
}