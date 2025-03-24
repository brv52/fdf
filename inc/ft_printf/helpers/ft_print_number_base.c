/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaltsev <nmaltsev@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 03:59:25 by nmaltsev          #+#    #+#             */
/*   Updated: 2024/06/13 03:59:36 by nmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_number_base(t_my_int *number, const char *base)
{
	size_t	base_len;
	int		digit;
	int		r_val;

	base_len = ft_spec_strlen(base);
	if (number->zeros)
	{
		ft_print_n('0', number->zeros);
		number->zeros = 0;
	}
	if (number->value < base_len)
		r_val = write(1, &base[number->value], 1);
	else
	{
		digit = number->value % base_len;
		number->value /= base_len;
		r_val = ft_print_number_base(number, base);
		r_val += write (1, &base[digit], 1);
	}
	return (r_val);
}
