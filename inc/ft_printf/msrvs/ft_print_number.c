/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaltsev <nmaltsev@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 04:00:13 by nmaltsev          #+#    #+#             */
/*   Updated: 2024/06/13 04:00:34 by nmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_number(t_format *form, va_list *args)
{
	t_my_int	number;

	ft_init_number(&number);
	ft_parse_number(form, &number, args);
	number.zeros = ft_max(form->precision - number.len, 0);
	form->width -= (number.zeros + number.len);
	if ((form->plus || number.sign || form->space)
		&& ft_is_in("di", form->type))
		form->width -= 1;
	if (number.prefix)
		form->width -= 2;
	if (form->width > number.zeros && form->zero)
	{
		number.zeros += (form->width - number.zeros);
		form->width = 0;
	}
	if (!form->minus)
		return (ft_print_n(' ', form->width) + ft_render_number(&number, form));
	else
		return (ft_render_number(&number, form) + ft_print_n(' ', form->width));
}
