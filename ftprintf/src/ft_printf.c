/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:05:22 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/01 12:37:48 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flag(t_pf_flag *flag)
{
	flag->sp = 0;
	flag->plus = 0;
	flag->neg = 0;
	flag->minus = 0;
	flag->hash = 0;
	flag->zero = 0;
	flag->prec = -1;
	flag->width = 0;
}

int		ft_printf(const char *restrict fmt, ...)
{
	t_pf_env	e;

	ft_bzero(&e, sizeof(e));
	e.fd = 1;
	va_start(e.ap[0], fmt);
	va_copy(e.ap[1], e.ap[0]);
	while (fmt[e.i])
	{
		if (fmt[e.i] == '{')
			check_settings(fmt, &e);
		else if (fmt[e.i] == '%' && fmt[e.i + 1] != '%' && fmt[e.i + 1])
			print_conversion(fmt, &e);
		else if (fmt[e.i] == '%' && fmt[e.i + 1] == '%')
		{
			e.ret += write(e.fd, "%", 1);
			e.i += 2;
		}
		else
			e.ret += write(e.fd, &fmt[e.i++], 1);
	}
	va_end(e.ap[0]);
	return (e.ret);
}
