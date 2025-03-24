/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaltsev <nmaltsev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:30:55 by nmaltsev          #+#    #+#             */
/*   Updated: 2024/11/13 17:29:38 by nmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_isdigit(const char c)
{
	return (c >= '0' && c <= '9');
}

static int	dif_sign(char **str)
{
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
		{
			*str += 1;
			return (-1);
		}
		else
		{
			*str += 1;
			return (1);
		}
	}
	return (1);
}

static void	trim_ws(char **str)
{
	while ((**str >= 9 && **str <= 13) || **str == 32)
		*str += 1;
}

float	ft_atoi(const char *nptr)
{
	char	*str;
	int		sign;
	float	res;

	res = 0.0f;
	str = (char *)nptr;
	trim_ws(&str);
	sign = dif_sign(&str);
	while (ft_isdigit(*str))
	{
		res *= 10;
		res += (float)(*str - '0');
		str += 1;
	}
	return (res * sign);
}
