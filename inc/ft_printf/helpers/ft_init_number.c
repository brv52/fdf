/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaltsev <nmaltsev@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 03:55:18 by nmaltsev          #+#    #+#             */
/*   Updated: 2024/06/13 03:55:19 by nmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_init_number(t_my_int *number)
{
	number->sign = 0;
	number->value = 0;
	number->len = 0;
	number->zeros = 0;
	number->prefix = 0;
}
