/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaltsev <nmaltsev@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 04:00:01 by nmaltsev          #+#    #+#             */
/*   Updated: 2024/06/13 04:00:08 by nmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_char(t_format *form, const char c)
{
	if (form->width > 1)
	{
		if (form->minus == 1)
		{
			return (write(1, &c, 1) + ft_print_n(' ', form->width - 1));
		}
		else
		{
			return (ft_print_n(' ', form->width - 1) + write(1, &c, 1));
		}
	}
	else
		return (write(1, &c, 1));
	return (-1);
}
