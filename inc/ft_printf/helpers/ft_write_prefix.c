/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_prefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaltsev <nmaltsev@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 03:57:31 by nmaltsev          #+#    #+#             */
/*   Updated: 2024/06/13 03:57:32 by nmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_write_prefix(t_my_int *number, const char type)
{
	if (number->value != 0 && (type == 'x' || type == 'p'))
		return (write(1, "0x", 2));
	else if (number->value != 0 && type == 'X')
		return (write(1, "0X", 2));
	return (0);
}
