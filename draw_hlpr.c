/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hlpr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borov <borov@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:17:24 by borov             #+#    #+#             */
/*   Updated: 2024/11/09 19:40:15 by borov            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_swap_points(t_point *start, t_point *end)
{
	ft_swap(&start->x, &end->x);
	ft_swap(&start->y, &end->y);
	ft_swap(&start->z, &end->z);
}

void	ft_init_bresenham_h(t_point *delta, t_point start,
	t_point end, int *dir)
{
	*dir = 1;
	delta->x = end.x - start.x;
	delta->y = end.y - start.y;
	delta->z = 0;
	if (delta->y < 0)
	{
		*dir = -1;
		delta->y = -delta->y;
	}
}
