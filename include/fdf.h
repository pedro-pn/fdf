/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:06:59 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/15 16:48:59 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"

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

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_bresendata
{
	int	x1;
	int	y1;
	int	xk;
	int	yk;
	int	dx;
	int	dy;
}			t_bresendata;

int				mod_x(int x);
void			draw_line_1(t_data *img, t_bresendata cord);
void			draw_line_2(t_data *img, t_bresendata cord);
void			draw_line_3(t_data *img, t_bresendata cord);
void			draw_line_4(t_data *img, t_bresendata cord);
void			bresen_alg(t_data *img, t_bresendata cord);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_bresendata	get_bresendata(int x1, int y1, int xk, int yk);

#endif
