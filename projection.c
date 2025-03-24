/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaltsev <nmaltsev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:35:10 by borov             #+#    #+#             */
/*   Updated: 2024/11/13 16:37:10 by nmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	ft_isometric(t_point p, float scale)
{
	int		x;
	int		y;
	float	angle;

	angle = PI / 4;
	x = p.x;
	y = p.y;
	p.x = (x - y) * cos(angle) * scale + WIDTH / 2;
	p.y = ((x + y) * sin(angle) - p.z) * scale + HEIGHT / 2;
	return (p);
}
