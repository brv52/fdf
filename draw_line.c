/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaltsev <nmaltsev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:24:55 by borov             #+#    #+#             */
/*   Updated: 2024/11/13 19:10:42 by nmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_acord_desc(int *decision, float *st, int dir, float dl)
{
	if (*decision >= 0)
	{
		*st += dir;
		*decision -= 2 * dl;
	}
}

void	ft_draw_line_bres_h(t_data *data, t_point start, t_point end,
		t_point *min_max)
{
	t_point	delta;
	t_point	stats;
	int		decision;
	int		dir;

	if (start.x > end.x)
		ft_swap_points(&start, &end);
	ft_init_bresenham_h(&delta, start, end, &dir);
	if (delta.x != 0)
	{
		stats.y = start.y;
		stats.z = start.z;
		decision = 2 * delta.y - delta.x;
		while (delta.z <= delta.x)
		{
			ft_pixel_put(data, start.x + delta.z, stats.y,
				ft_color_from_z(min_max, start.z + delta.z / delta.x * (end.z
						- start.z)));
			ft_acord_desc(&decision, &stats.y, dir, delta.x);
			decision += 2 * delta.y;
			delta.z += 1;
		}
	}
}

void	ft_init_bresenham_v(t_point *delta, t_point start, t_point end,
		int *dir)
{
	*dir = 1;
	delta->x = end.x - start.x;
	delta->y = end.y - start.y;
	delta->z = 0;
	if (delta->x < 0)
	{
		*dir = -1;
		delta->x = -delta->x;
	}
}

void	ft_draw_line_bres_v(t_data *data, t_point start, t_point end,
		t_point *min_max)
{
	t_point	delta;
	t_point	stats;
	int		decision;
	int		dir;

	if (start.y > end.y)
		ft_swap_points(&start, &end);
	ft_init_bresenham_v(&delta, start, end, &dir);
	if (delta.y != 0)
	{
		stats.x = start.x;
		stats.z = start.z;
		decision = 2 * delta.x - delta.y;
		while (delta.z <= delta.y)
		{
			ft_pixel_put(data, stats.x, start.y + delta.z,
				ft_color_from_z(min_max, start.z + delta.z / delta.y * (end.z
						- start.z)));
			ft_acord_desc(&decision, &stats.x, dir, delta.y);
			decision += 2 * delta.x;
			delta.z += 1;
		}
	}
}
