/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:05:22 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/06 19:18:11 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *restrict frmt, ...)
{
	t_pf_env	o;

	ft_bzero(&o, sizeof(o));
	o.fd = 1;
	va_start(o.ap[0], frmt);
	start_fpf(frmt, &o);
	va_end(o.ap[0]);
	return (o.ret);
}

void	start_fpf(const char *restrict frmt, t_pf_env *o)
{
	while (frmt[o->i])
	{
		if (IPRSNT(frmt[o->i]) && !frmt[o->i + 1])
		{
			o->ret = 0;
			break ;
		}
		else if (IPRSNT(frmt[o->i]) && !IPRSNT(frmt[o->i + 1]))
		{
			++o->i;
			get_tags(frmt, o);
			get_flags(frmt, o);
			get_specs(frmt, o);
		}
		else if (IPRSNT(frmt[o->i]) && IPRSNT(frmt[o->i + 1]))
		{
			o->ret += write(o->fd, "%", 1);
			o->i += 2;
		}
		else
			o->ret += write(o->fd, &frmt[o->i++], 1);
	}
}

void	parse_flags(const char *restrict frmt, t_pf_env *o)
{
	while (ft_strchr(I_FLAG, frmt[o->i]))
	{
		frmt[o->i] == ' ' ? o->flag.sps = 1 : 0;
		frmt[o->i] == '-' ? o->flag.minus = 1 : 0;
		frmt[o->i] == '+' ? o->flag.plus = 1 : 0;
		frmt[o->i] == '#' ? o->flag.hash = 1 : 0;
		frmt[o->i] == '0' ? o->flag.zero = 1 : 0;
		if (frmt[o->i] >= 'L' && frmt[o->i] <= 'z')
			get_mods(frmt, o);
		if (frmt[o->i] == '*')
			get_width(o);
		if (frmt[o->i] == '.')
			get_prec(frmt, o);
		else if (INUM1(frmt[o->i]) && o->flag.prec < 0)
		{
			o->flag.width = ft_atoi(frmt + o->i);
			while (INUM(frmt[o->i]))
				++o->i;
		}
		else
			++o->i;
	}
}