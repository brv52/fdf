/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaltsev <nmaltsev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:23:56 by borov             #+#    #+#             */
/*   Updated: 2024/11/13 18:30:27 by nmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mesh(t_mesh *mesh)
{
	mesh->data = NULL;
	mesh->idx = -1;
	mesh->len = -1;
	mesh->size = -1;
	ft_set_pos(&mesh->min_max, 2147483647, -2147483647, 0);
}

int	main(int argc, char **argv)
{
	t_data	img;
	t_mesh	m;
	t_vars	v;

	if (argc != 2)
		return (0);
	init_mesh(&m);
	m = ft_read_file(argv[1]);
	if (m.size < 0)
		return (0);
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "TITLE");
	img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	img.scale = 1;
	draw_mesh(&img, &m);
	v.img = &img;
	v.mesh = &m;
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_key_hook(img.win, ft_proceed_input, &v);
	mlx_hook(img.win, 17, 0, close_window, &img);
	mlx_loop(img.mlx);
	free_mesh(&m);
	return (0);
}
