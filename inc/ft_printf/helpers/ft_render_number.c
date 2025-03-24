/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaltsev <nmaltsev@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 03:58:11 by nmaltsev          #+#    #+#             */
/*   Updated: 2024/06/13 03:59:09 by nmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_render_number(t_my_int *number, t_format *form)
{
	int	prefix;

	prefix = 0;
	if (number->prefix == 1 && !(form->type == 'p' && number->value == 0))
		prefix = ft_write_prefix(number, form->type);
	if (ft_is_in("diu", form->type))
		return (number->zeros
			+ ft_render_sign(number, form)
			+ ft_print_number_base(number, BASE_10));
	else if (form->type == 'X')
		return (number->zeros
			+ ft_print_number_base(number, BASE_16_HIGH) + prefix);
	else if (form->type == 'p' && number->value == 0)
		return (write(1, "(nil)", 5));
	else
		return (number->zeros
			+ ft_print_number_base(number, BASE_16_LOW) + prefix);
}
