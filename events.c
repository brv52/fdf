/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaltsev <nmaltsev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:34:49 by borov             #+#    #+#             */
/*   Updated: 2024/11/13 16:38:29 by nmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->mlx && data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

void	move_mesh(t_mesh *mesh, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < mesh->size)
	{
		j = 0;
		while (j < mesh->len)
		{
			mesh->data[i][j].x += x;
			mesh->data[i][j].y += y;
			j++;
		}
		i++;
	}
}

void	ft_update_screen(t_data *data, t_mesh *mesh)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	draw_mesh(data, mesh);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int	ft_proceed_input(int keycode, void *param)
{
	t_vars	*vars;
	t_data	*data;
	t_mesh	*mesh;

	vars = (t_vars *)param;
	data = vars->img;
	mesh = vars->mesh;
	if (keycode == 65307)
		close_window(data);
	else if (keycode == 65361)
		move_mesh(mesh, -G_CELL_SIZE, 0);
	else if (keycode == 65362)
		move_mesh(mesh, 0, -G_CELL_SIZE);
	else if (keycode == 65363)
		move_mesh(mesh, G_CELL_SIZE, 0);
	else if (keycode == 65364)
		move_mesh(mesh, 0, G_CELL_SIZE);
	else if (keycode == 117)
		data->scale += 0.1f;
	else if (keycode == 100)
		data->scale -= 0.1f;
	ft_update_screen(data, mesh);
	return (0);
}
