/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:46:13 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/16 16:34:54 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_win_data
{
	void	*mlx;
	void	*mlx_win;
}				t_win_data;

int	exit_win(int key, void *param)
{
	if (key == 65307)
	{
		mlx_clear_window(((t_win_data *)param)->mlx, ((t_win_data *)param)->mlx_win);
		mlx_destroy_window(((t_win_data *)param)->mlx, ((t_win_data *)param)->mlx_win);
		mlx_loop_end(((t_win_data *)param)->mlx);
	}
	return (0);
}

int main()
{
	// void	*mlx;
	// void	*mlx_win;
	t_win_data	*mlx_data;
	int i;
	int j;
	int x;
	int y;
	int xk;
	int **matrix;
	char	**map;
	int	num_lines;
//	int yk;
	
	t_data	img;
	t_bresendata	cord;
	
	mlx_data = malloc(sizeof(t_win_data));
	num_lines = count_lines("./srcs/42.fdf");
	map = fill_map("./srcs/42.fdf", num_lines);
	matrix = get_matrix(map, num_lines);
	
	//ft_printf("Potencia: %d\n", power(2, 4));
	mlx_data->mlx = mlx_init();
	mlx_data->mlx_win = mlx_new_window(mlx_data->mlx, 800, 600, "Hello World!");
	img.img = mlx_new_image(mlx_data->mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//	x = 1;
//	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	//bren_alg(&img, 0, 0, 60, 40);
	i = 0;
	j = 0;
	ft_printf("%d\n", matrix[5][j]);
	while (j < num_lines)
	{
		i = 0;
		y = (600/2) + (10*j);
		while (i < 18)
		{
			x = (i*10) + (800/2);
			xk = x + 10;
			if (matrix[j][i] == matrix[j][i+1])
			{
				cord = get_bresendata(x, y, xk, y);
				bresen_alg(&img, cord);
			}
		//	x = xk;
			i++;
		}
		j++;
	}
	i = 0;
	j = 0;
	while (j < 19)
	{
		i = 0;
		y = (800/2) + (10*j);
		while (i < num_lines - 1)
		{
			x = (i*10) + (600/2);
			xk = x + 10;
			if (matrix[i][j] == matrix[i+1][j])
			{
				cord = get_bresendata(y, x, y, xk);
				bresen_alg(&img, cord);	
			}
		//	x = xk;
			i++;
		}
		j++;
	}
	//cord = get_bresendata(X, Y, XK, YK); // pega os (x, y) (x, y) pra formatar
	//bresen_alg(&img, cord); // plota formatado
	// while (x < 50)
	// {
	// 	y = 5 * x + 58;
	// 	my_mlx_pixel_put(&img, x, y, 0X00FF0000);
	// 	x++;
	// }
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win, img.img, 0, 0);
	mlx_key_hook(mlx_data->mlx_win, exit_win, mlx_data);
	mlx_destroy_image(mlx_data->mlx, img.img);
	mlx_loop(mlx_data->mlx);
	mlx_destroy_display(mlx_data->mlx);
	free(mlx_data->mlx);
	// free(img.img);
	//free(img.addr);
	
	free(mlx_data);
}

