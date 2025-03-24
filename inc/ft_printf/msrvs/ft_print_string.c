/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaltsev <nmaltsev@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 04:00:38 by nmaltsev          #+#    #+#             */
/*   Updated: 2024/06/13 04:01:34 by nmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_string(t_format *form, const char *str)
{
	if (str == NULL)
		str = "(null)";
	if (form->precision == -1 || form->precision > ft_spec_strlen(str))
		form->precision = ft_spec_strlen(str);
	form->width -= form->precision;
	if (form->width >= 1)
	{
		if (form->minus == 1)
			return (write(1, str, form->precision)
				+ ft_print_n(' ', form->width));
		else
			return (ft_print_n(' ', form->width)
				+ write(1, str, form->precision));
	}
	else
		write(1, str, form->precision);
	return (ft_max(form->width, 0) + form->precision);
}
