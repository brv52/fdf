/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_number_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaltsev <nmaltsev@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 03:56:16 by nmaltsev          #+#    #+#             */
/*   Updated: 2024/06/13 03:56:16 by nmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_get_number_len(t_my_int number, const char type)
{
	unsigned int	b_len;
	int				res;

	if (ft_is_in("diu", type))
		b_len = ft_spec_strlen(BASE_10);
	else
		b_len = ft_spec_strlen(BASE_16_LOW);
	res = 0;
	if (number.value == 0)
		return (1);
	while (number.value > 0)
	{
		res += 1;
		number.value /= b_len;
	}
	return (res);
}
