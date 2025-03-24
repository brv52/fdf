/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaltsev <nmaltsev@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 03:57:09 by nmaltsev          #+#    #+#             */
/*   Updated: 2024/06/13 03:57:23 by nmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_parse_number(t_format *form, t_my_int *number, va_list *args)
{
	unsigned long	arg;
	long			b_arg;

	arg = 0;
	b_arg = 0;
	if (ft_is_in("di", form->type))
		b_arg = (long)va_arg(*args, int);
	else if (form->type == 'p')
		arg = (unsigned long)va_arg(*args, void *);
	else
		arg = (unsigned long)va_arg(*args, unsigned int);
	number->sign = (b_arg < 0);
	number->value = arg | b_arg;
	if (number->sign == 1)
		number->value *= -1;
	number->len = ft_get_number_len(*number, form->type);
	if (form->hash || form->type == 'p')
		number->prefix = 1;
}
