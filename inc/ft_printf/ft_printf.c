/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaltsev <nmaltsev@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 03:53:57 by nmaltsev          #+#    #+#             */
/*   Updated: 2024/06/13 03:54:59 by nmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_format(t_format *format, va_list *args)
{
	if (format->type == 'c')
	{
		return (ft_print_char(format, va_arg(*args, int)));
	}
	else if (format->type == 's')
	{
		return (ft_print_string(format, va_arg(*args, char *)));
	}
	else if (format->type == '%')
	{
		return (write(1, "%", 1));
	}
	else if (ft_is_in("diuxXp", format->type))
	{
		return (ft_print_number(format, args));
	}
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	t_format	form;
	int			count;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str += 1;
			form = ft_parse_format(&str, &args);
			count += ft_print_format(&form, &args);
		}
		else
			count += write(1, str, 1);
		str += 1;
	}
	va_end(args);
	return (count);
}
