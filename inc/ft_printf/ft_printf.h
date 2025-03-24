/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaltsev <nmaltsev@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:14:50 by nmaltsev          #+#    #+#             */
/*   Updated: 2024/06/13 03:58:03 by nmaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define BASE_10 "0123456789"
# define BASE_16_LOW "0123456789abcdef"
# define BASE_16_HIGH "0123456789ABCDEF"

typedef struct format
{
	int		plus;
	int		minus;
	int		hash;
	int		space;
	int		zero;
	int		width;
	int		precision;
	char	type;
}	t_format;

typedef struct my_int
{
	unsigned long	value;
	int				sign;
	int				len;
	int				zeros;
	int				prefix;
}	t_my_int;

t_format	ft_parse_format(const char **str, va_list *args);
int			ft_max(int a, int b);
int			ft_is_flag(const char c);
int			ft_is_digit(const char c);
int			ft_is_in(const char *str, const char c);
int			ft_spec_atoi(const char **str);
int			ft_write_prefix(t_my_int *number, const char type);
int			ft_print_n(const char c, int n);
int			ft_spec_strlen(const char *str);
int			ft_print_char(t_format *form, const char c);
int			ft_print_string(t_format *form, const char *str);
int			ft_get_number_len(t_my_int number, const char type);
int			ft_print_number_base(t_my_int *number, const char *base);
int			ft_render_number(t_my_int *number, t_format *form);
int			ft_print_number(t_format *form, va_list *args);
int			ft_printf(const char *str, ...);
int			ft_render_sign(t_my_int *number, t_format *form);
void		ft_init_form(t_format *form);
void		ft_init_number(t_my_int *number);
void		ft_parse_number(t_format *form, t_my_int *number, va_list *args);
#endif
