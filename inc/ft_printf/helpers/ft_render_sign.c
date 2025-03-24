/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_sign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaltsev <nmaltsev@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 03:56:44 by nmaltsev          #+#    #+#             */
/*   Updated: 2024/06/13 03:56:58 by nmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_render_sign(t_my_int *number, t_format *form)
{
	if (number->sign == 1)
		return (write (1, "-", 1));
	else if (form->plus == 1)
		return (write (1, "+", 1));
	else if (form->space)
		return (write (1, " ", 1));
	return (0);
}
