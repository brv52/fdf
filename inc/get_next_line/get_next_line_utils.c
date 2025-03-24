/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaltsev <nmaltsev@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:45:13 by nmaltsev          #+#    #+#             */
/*   Updated: 2024/06/17 00:18:18 by nmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(char *str)
{
	int	res;

	if (!str || str == NULL)
		return (0);
	res = 0;
	while (str[res])
		res += 1;
	return (res);
}

char	*gnl_strchr(char *str, char c)
{
	if (!str || str == NULL)
		return (NULL);
	while (*str && *str != c)
		str += 1;
	if (*str == c)
		return (str);
	return (NULL);
}

char	*gnl_strjoin(char *a, char *b)
{
	char	*res;
	int		r_size;

	r_size = gnl_strlen(a) + gnl_strlen(b);
	res = gnl_crstr(r_size);
	r_size = 0;
	while (a && *a)
		res[r_size++] = *a++;
	while (b && *b)
		res[r_size++] = *b++;
	return (res);
}

char	*gnl_crstr(int size)
{
	char	*res;

	if (size <= 0)
		return (NULL);
	res = malloc(size + 1);
	while (size >= 0)
		res[size--] = '\0';
	return (res);
}
