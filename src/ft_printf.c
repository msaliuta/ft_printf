/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:05:22 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/07 20:40:55 by msaliuta         ###   ########.fr       */
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
		if (CHECK_PCNT(frmt[o->i]) && !frmt[o->i + 1])
		{
			o->ret = 0;
			break ;
		}
		else if (CHECK_PCNT(frmt[o->i]) && !CHECK_PCNT(frmt[o->i + 1]))
		{
			++o->i;
			parse_mfw(frmt, o);
			parse_flags(frmt, o);
			parse_size_spec(frmt, o);
		}
		else if (CHECK_PCNT(frmt[o->i]) && CHECK_PCNT(frmt[o->i + 1]))
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
	while (ft_strchr(FLAGS, frmt[o->i]))
	{
		if (frmt[o->i] >= 'L' && frmt[o->i] <= 'z')
			parce_modif(frmt, o);
		if (ft_strchr(CONV_FLAGS, frmt[o->i]))
			check_conv_flag(frmt, o);
		if (frmt[o->i] == '*')
			check_width(o);
		if (frmt[o->i] == '.')
			check_prec(frmt, o);
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

void	check_conv_flag(const char *restrict frmt, t_pf_env *o)
{
	if (frmt[o->i] == ' ')
		o->flag.sps = 1;
	if (frmt[o->i] == '-')
		o->flag.minus = 1;
	if (frmt[o->i] == '+')
		o->flag.plus = 1;
	if (frmt[o->i] == '#')
		o->flag.hash = 1;
	if (frmt[o->i] == '0')
		o->flag.zero = 1;
}

void	parce_modif(const char *restrict frmt, t_pf_env *o)
{
	if (frmt[o->i] == 'h' && frmt[o->i + 1] != 'h')
		o->mod = pf_h;
	else if (frmt[o->i] == 'h' && frmt[o->i + 1] == 'h')
	{
		o->mod = pf_hh;
		++o->i;
	}
	else if (frmt[o->i] == 'l' && frmt[o->i + 1] != 'l')
		o->mod = pf_l;
	else if (frmt[o->i] == 'l' && frmt[o->i + 1] == 'l')
	{
		o->mod = pf_ll;
		++o->i;
	}
	else if (frmt[o->i] == 'z')
		o->mod = pf_z;
	else if (frmt[o->i] == 'j')
		o->mod = pf_j;
	else if (frmt[o->i] == 'L')
		o->mod = pf_L;
	else if (frmt[o->i] == 't')
		o->mod = pf_t;
}
