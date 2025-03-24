/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaltsev <nmaltsev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:24:32 by borov             #+#    #+#             */
/*   Updated: 2024/11/13 19:09:49 by nmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_offset(int x, int y, t_data *data)
{
	return (y * data->line_len + x * (data->bpp / 8));
}

void	ft_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr + ft_offset(x, y, data);
		*(unsigned int *)dst = color;
	}
}

int	ft_color_from_z(t_point *min_max, float z)
{
	int		r;
	int		g;
	int		b;
	float	percentage;

	percentage = (z - min_max->x) / (min_max->y - min_max->x);
	if (percentage < 0.0f)
		percentage = 0.0f;
	else if (percentage > 1.0f)
		percentage = 1.0f;
	r = ((COL >> 16) & 0xFF) + percentage * (((COL2 >> 16) & 0xFF)
			- ((COL >> 16) & 0xFF));
	g = ((COL >> 8) & 0xFF) + percentage * (((COL2 >> 8) & 0xFF)
			- ((COL >> 8) & 0xFF));
	b = (COL & 0xFF) + percentage * ((COL2 & 0xFF) - (COL & 0xFF));
	return ((r << 16) | (g << 8) | b);
}

void	ft_draw_line(t_data *data, t_point start, t_point end, t_point *min_max)
{
	if (ft_fabs(end.x - start.x) > ft_fabs(end.y - start.y))
		ft_draw_line_bres_h(data, start, end, min_max);
	else
		ft_draw_line_bres_v(data, start, end, min_max);
}

void	draw_mesh(t_data *img, t_mesh *mesh)
{
	int	i;
	int	j;

	i = 0;
	while (i < mesh->size)
	{
		j = 0;
		while (j < mesh->len)
		{
			if (j != 0)
				ft_draw_line(img, ft_isometric(mesh->data[i][j], img->scale),
					ft_isometric(mesh->data[i][j - 1], img->scale),
					&mesh->min_max);
			if (i != 0)
				ft_draw_line(img, ft_isometric(mesh->data[i][j], img->scale),
					ft_isometric(mesh->data[i - 1][j], img->scale),
					&mesh->min_max);
			j++;
		}
		i++;
	}
}
