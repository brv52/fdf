/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaltsev <nmaltsev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:33:35 by borov             #+#    #+#             */
/*   Updated: 2024/11/13 18:26:43 by nmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count_points(char *line)
{
	int	res;
	int	idx;

	res = 0;
	idx = 0;
	while (line && line[idx] != '\0')
	{
		if (line[idx] == ' ')
			res++;
		while (line[idx] == ' ')
			idx++;
		idx++;
	}
	return (res);
}

void	ft_get_lines(const char *filename, t_mesh *m)
{
	char	*line;
	int		fd;
	int		points;

	m->size = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	points = ft_count_points(line);
	while (line != NULL)
	{
		free(line);
		m->size++;
		line = get_next_line(fd);
	}
	close(fd);
	m->len = points + 1;
}

t_point	*ft_parse_line(char *line, t_mesh *m)
{
	t_point	*vec;
	t_point	cord;
	int		idx;

	idx = 0;
	ft_set_pos(&cord, 0, m->idx, 0);
	vec = (t_point *)malloc(m->len * sizeof(t_point));
	while (*line != '\0' && idx < m->len)
	{
		ft_set_pos(&vec[idx], cord.x * G_CELL_SIZE,
			cord.y * G_CELL_SIZE, ft_atoi(line));
		if (vec[idx].z < m->min_max.x)
			m->min_max.x = vec[idx].z;
		if (vec[idx].z > m->min_max.y)
			m->min_max.y = vec[idx].z;
		idx += 1;
		cord.x += 1;
		while (*line != ' ' && *line != '\0')
			line++;
		while (*line == ' ' && *line != '\0')
			line++;
	}
	return (vec);
}

t_mesh	ft_read_file(const char *filename)
{
	char	*line;
	int		fd;
	t_mesh	mesh;

	fd = open(filename, O_RDONLY);
	if (!fd || fd < 0)
	{
		mesh.size = -1;
		close(fd);
		return (mesh);
	}
	ft_get_lines(filename, &mesh);
	mesh.data = malloc(mesh.size * sizeof(t_point *));
	mesh.idx = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		mesh.data[mesh.idx] = ft_parse_line(line, &mesh);
		mesh.idx++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (mesh);
}

void	free_mesh(t_mesh *mesh)
{
	int	i;

	i = 0;
	while (i < mesh->size)
	{
		free(mesh->data[i]);
		i++;
	}
	free(mesh->data);
}
