#include "fdf.h"

int main()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	
	//ft_printf("Potencia: %d\n", power(2, 4));
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "Hello World!");
	img.img = mlx_new_image(mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//	x = 1;
//	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	//bren_alg(&img, 0, 0, 60, 40);
	//bren_alg(&img, 60, 40, 0, 0);
	//bren_alg(&img, 0, 0, 40, 60);
	//bren_alg(&img, 40, 60, 0, 0);
	// bren_alg(&img, 40, 0, 0, 60);
	// bren_alg(&img, 0, 60, 40, 0);
	// bren_alg(&img, 0, 40, 60, 0);
	 bren_alg(&img, 60, 0, 0, 40);
	// while (x < 50)
	// {
	// 	y = 5 * x + 58;
	// 	my_mlx_pixel_put(&img, x, y, 0X00FF0000);
	// 	x++;
	// }
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

