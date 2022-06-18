/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:06:59 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/18 01:25:57 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

# define SCREEN_WIDTH 1024
# define SCREEN_LENGTH 768
# define SIZE_LINE 50
# ifndef X
#  define X 0
# endif

# ifndef Y
#  define Y 0
# endif

# ifndef XK
#  define XK 60
# endif

# ifndef YK
#  define YK 40
# endif

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_bresendata
{
	int	x1;
	int	y1;
	int	xk;
	int	yk;
	int	dx;
	int	dy;
}			t_bresendata;

typedef struct s_fdf
{
	int		num_columns;
	int		num_rows;
	int		**matrix;
	char	**map;
}			t_fdf;

typedef struct s_win_data
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
}				t_win_data;

int				mod_x(int x);
void			draw_line_1(t_img *img, t_bresendata cord);
void			draw_line_2(t_img *img, t_bresendata cord);
void			draw_line_3(t_img *img, t_bresendata cord);
void			draw_line_4(t_img *img, t_bresendata cord);
void			bresen_alg(t_img *img, t_bresendata cord);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
t_bresendata	get_bresendata(int x1, int y1, int xk, int yk);
int				**get_matrix(char **map, int num_lines);
int				count_lines(char *file_name);
char			**fill_map(char *file_name, int lines);
int				exit_win(int key, void *param);
int				get_rows(char **splitted_line);
int				clean_matrix(void **matrix);
void			plot_lines(t_win_data mlx_data, t_fdf fdf);
void			plot_rows(t_win_data mlx_data, t_fdf fdf);
void	plot_lines_iso(t_win_data mlx_data, t_fdf fdf);
void	plot_rows_iso(t_win_data mlx_data, t_fdf fdf);

#endif
