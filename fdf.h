/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaltsev <nmaltsev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:16:05 by borov             #+#    #+#             */
/*   Updated: 2024/11/13 19:48:56 by nmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "inc/ft_printf/ft_printf.h"
# include "inc/get_next_line/get_next_line.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <math.h>

# define WIDTH 1000
# define HEIGHT 1000
# define G_CELL_SIZE 10
# define COL 0x00FFAA11
# define COL2 0x00AA11FF
# define FOV 60
# define PI 3.14159265358979323846

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	void	*win;
	void	*mlx;
	float	scale;
}			t_data;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}			t_point;

typedef struct s_mesh
{
	t_point	**data;
	int		len;
	int		size;
	int		idx;
	t_point	min_max;
}			t_mesh;

typedef struct s_vars
{
	t_data	*img;
	t_mesh	*mesh;
}			t_vars;

void		ft_set_pos(t_point *p, float x, float y, float z);
int			ft_offset(int x, int y, t_data *data);
float		ft_fabs(float a);
void		ft_pixel_put(t_data *data, int x, int y, int color);
void		ft_swap(float *a, float *b);
void		ft_draw_line(t_data *data, t_point start, t_point end,
				t_point *min_max);
void		ft_point_mul(t_point *p, float scale);
void		ft_rot_x(t_point *p, float angle);
int			ft_count_points(char *line);
void		ft_get_lines(const char *filename, t_mesh *m);
t_point		*ft_parse_line(char *line, t_mesh *m);
t_mesh		ft_read_file(const char *filename);
t_point		ft_isometric(t_point p, float scale);
int			close_window(void *param);
void		move_mesh(t_mesh *mesh, int x, int y);
int			ft_proceed_input(int keycode, void *param);
void		free_mesh(t_mesh *mesh);
void		draw_mesh(t_data *img, t_mesh *mesh);
int			ft_color_from_z(t_point *min_max, float z);
void		ft_swap_points(t_point *start, t_point *end);
void		ft_init_bresenham_h(t_point *delta, t_point start, t_point end,
				int *dir);
void		ft_draw_line_bres_h(t_data *data, t_point start, t_point end,
				t_point *min_max);
void		ft_init_bresenham_v(t_point *delta, t_point start, t_point end,
				int *dir);
void		ft_draw_line_bres_v(t_data *data, t_point start, t_point end,
				t_point *min_max);
float		ft_atoi(const char *nptr);

#endif
