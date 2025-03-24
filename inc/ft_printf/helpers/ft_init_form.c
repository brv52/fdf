/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_form.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaltsev <nmaltsev@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 03:56:28 by nmaltsev          #+#    #+#             */
/*   Updated: 2024/06/13 03:56:29 by nmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_init_form(t_format *form)
{
	form->plus = 0;
	form->minus = 0;
	form->hash = 0;
	form->space = 0;
	form->zero = 0;
	form->width = -1;
	form->precision = -1;
	form->type = ' ';
}
