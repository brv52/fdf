/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaltsev <nmaltsev@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 03:59:18 by nmaltsev          #+#    #+#             */
/*   Updated: 2024/06/13 03:59:19 by nmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_is_in(const char *str, const char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str += 1;
	}
	return (0);
}
