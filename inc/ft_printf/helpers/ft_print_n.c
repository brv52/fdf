/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaltsev <nmaltsev@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 03:55:50 by nmaltsev          #+#    #+#             */
/*   Updated: 2024/06/13 03:56:03 by nmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_n(const char c, int n)
{
	int	r_val;

	r_val = n;
	if (n < 0)
		return (0);
	while (n--)
		write(1, &c, 1);
	return (r_val);
}
