/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaltsev <nmaltsev@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 03:59:51 by nmaltsev          #+#    #+#             */
/*   Updated: 2024/06/13 03:59:55 by nmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_spec_atoi(const char **str)
{
	int	res;

	res = 0;
	while (**str && ft_is_digit(**str))
	{
		res *= 10;
		res += **str - '0';
		*str += 1;
	}
	return (res);
}
