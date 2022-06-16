/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:46:13 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/16 20:43:47 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"

int main()
{
	// void	*mlx;
	// void	*mlx_win;
	t_win_data	mlx_data;
	int i;
	int j;
	int x;
	int y;
	int xk;
	int **matrix;
	char	**map;
	int	num_lines;
	//int	*exit_func;
//	int yk;
//	exit_func = &(exit_win)(int key, void *param)));
	t_img	img;
	t_bresendata	cord;
	
	//mlx_data = malloc(sizeof(t_win_data));
	num_lines = count_lines("./maps/42.fdf");
	map = fill_map("./maps/42.fdf", num_lines);
	matrix = get_matrix(map, num_lines);
	
	//ft_printf("Potencia: %d\n", power(2, 4));
	mlx_data.mlx = mlx_init();
	mlx_data.mlx_win = mlx_new_window(mlx_data.mlx, 800, 600, "Hello World!");
	img.img = mlx_new_image(mlx_data.mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//	x = 1;
//	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	//bren_alg(&img, 0, 0, 60, 40);
	i = 0;
	j = 0;
	ft_printf("%d\n", matrix[5][j]);
	int meio_x;
	int meio_y;
	meio_y = (600/2) - (num_lines/2) * 20;
	meio_x = (800 / 2) - (18 / 2) * 20;
	while (j < num_lines)
	{
		i = 0;
		y = meio_y + (20*j);
		while (i < 18)
		{
			x = (i*20) + meio_x;
			xk = x + 20;
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
		y = meio_x + (20*j);
		while (i < num_lines - 1)
		{
			x = (i*20) + meio_y;
			xk = x + 20;
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
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.mlx_win, img.img, 0, 0);
	mlx_key_hook(mlx_data.mlx_win, &exit_win, &mlx_data);
	mlx_destroy_image(mlx_data.mlx, img.img);
	mlx_loop(mlx_data.mlx);
	mlx_destroy_display(mlx_data.mlx);
	free(mlx_data.mlx);
	// free(img.img);
	//free(img.addr);
	while (num_lines >= 0)
    {
        free(map[num_lines]);
        num_lines--;
    }
    free(map);
	int index_matrix = 0;
	while (matrix[index_matrix])
    {
        free(matrix[index_matrix]);
        index_matrix++;
    }
    free(matrix);
	
//	free(mlx_data);
}

