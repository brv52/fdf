/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaltsev <nmaltsev@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 04:01:42 by nmaltsev          #+#    #+#             */
/*   Updated: 2024/06/13 04:03:38 by nmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_get_flags(const char **str, t_format *form)
{
	while (**str && ft_is_flag(**str))
	{
		if (**str == '+')
			form->plus = 1;
		if (**str == '#')
			form->hash = 1;
		if (**str == ' ')
			form->space = 1;
		if (**str == '0')
			form->zero = 1;
		if (**str == '-')
			form->minus = 1;
		*str += 1;
	}
}

t_format	ft_parse_format(const char **str, va_list *args)
{
	t_format	form;

	ft_init_form(&form);
	ft_get_flags(str, &form);
	if (**str && ft_is_digit(**str))
		form.width = ft_spec_atoi(str);
	else if (**str && **str == '*')
	{
		form.width = va_arg(*args, int);
		*str += 1;
	}
	if (**str && **str == '.')
	{
		*str += 1;
		if (**str && **str == '*')
		{
			form.precision = va_arg(*args, int);
			*str += 1;
		}
		else
			form.precision = ft_spec_atoi(str);
	}
	form.type = **str;
	return (form);
}
