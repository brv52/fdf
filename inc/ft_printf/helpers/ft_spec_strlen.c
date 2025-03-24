/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaltsev <nmaltsev@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 03:57:40 by nmaltsev          #+#    #+#             */
/*   Updated: 2024/06/13 03:57:51 by nmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_spec_strlen(const char *str)
{
	int	res;

	res = 0;
	while (str[res])
		res += 1;
	return (res);
}
