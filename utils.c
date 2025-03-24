/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borov <borov@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:24:19 by borov             #+#    #+#             */
/*   Updated: 2024/11/09 18:24:20 by borov            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_pos(t_point *p, float x, float y, float z)
{
	p->x = x;
	p->y = y;
	p->z = z;
}

void	ft_swap(float *a, float *b)
{
	float	c;

	c = *a;
	*a = *b;
	*b = c;
}

float	ft_fabs(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	ft_point_mul(t_point *p, float scale)
{
	p->x *= scale;
	p->y *= scale;
	p->z *= scale;
}

void	ft_rot_x(t_point *p, float angle)
{
	float	temp_y;
	float	temp_z;

	temp_y = p->y;
	temp_z = p->z;
	p->y = cos(angle) * temp_y - sin(angle) * temp_z;
	p->z = sin(angle) * temp_y + cos(angle) * temp_z;
}
