/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaltsev <nmaltsev@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 23:21:07 by nmaltsev          #+#    #+#             */
/*   Updated: 2024/06/17 00:18:19 by nmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_append(char *buffer, char *app)
{
	char	*tmp;

	tmp = gnl_strjoin(buffer, app);
	free(buffer);
	return (tmp);
}

static char	*gnl_extract_line(char **buffer)
{
	char	*res;
	char	*n_buffer;
	int		n_pos;

	if (!*buffer)
		return (NULL);
	n_pos = gnl_strchr(*buffer, '\n') - *buffer;
	if (n_pos < 0)
	{
		res = gnl_strjoin(NULL, *buffer);
		free (*buffer);
		*buffer = NULL;
		return (res);
	}
	n_buffer = gnl_strjoin(NULL, (*buffer + n_pos + 1));
	(*buffer)[n_pos + 1] = '\0';
	res = gnl_strjoin(NULL, *buffer);
	free(*buffer);
	*buffer = n_buffer;
	return (res);
}

static char	*gnl_read_buffer(char *buffer, int fd)
{
	char	*buffer_tmp;
	int		r_bytes;

	buffer_tmp = gnl_crstr(BUFFER_SIZE);
	r_bytes = 1;
	while (r_bytes > 0 && gnl_strchr(buffer_tmp, '\n') == NULL)
	{
		r_bytes = read(fd, buffer_tmp, BUFFER_SIZE);
		if (r_bytes < 0)
		{
			free(buffer_tmp);
			return (NULL);
		}
		buffer_tmp[r_bytes] = '\0';
		buffer = gnl_append(buffer, buffer_tmp);
		if (gnl_strchr(buffer_tmp, '\n'))
			break ;
	}
	free(buffer_tmp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*res;

	buffer = gnl_read_buffer(buffer, fd);
	if (!buffer)
		return (NULL);
	res = gnl_extract_line(&buffer);
	return (res);
}
