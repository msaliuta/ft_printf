/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mfw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 07:06:53 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/07 20:40:54 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_mfw(const char *restrict fmt, t_pf_env *e)
{
	int	i;
	int tmp;

	i = 0;
	e->flag.sps = 0;
	e->flag.plus = 0;
	e->flag.neg = 0;
	e->flag.minus = 0;
	e->flag.hash = 0;
	e->flag.zero = 0;
	e->flag.prec = -1;
	e->flag.width = 0;
	if (INUM(fmt[e->i]))
	{
		tmp = ft_atoi(fmt + e->i);
		while (INUM(fmt[e->i + i]))
			i++;
		if (fmt[e->i + i] == '$')
		{
			e->tag.tag = 1;
			e->tag.pos = tmp;
			e->i += i + 1;
		}
	}
}

void	parse_size_spec(const char *restrict fmt, t_pf_env *e)
{
	if (fmt[e->i] == '%')
		process_percent(e);
	else if (CHECK_INT(fmt[e->i]) && e->mod != pf_z)
		process_int(e);
	else if (CHECK_UINT(fmt[e->i]) || (CHECK_INT(fmt[e->i]) && e->mod == pf_z))
		process_unsint(e, fmt[e->i]);
	else if (CHECK_CHR(fmt[e->i]) && e->mod != pf_l)
		spec_char(e, fmt[e->i]);
	else if (CHECK_LCHR(fmt[e->i]))
		spec_char(e, fmt[e->i] + 32);
	else if ((CHECK_CHR(fmt[e->i]) && e->mod == pf_l) ||
			CHECK_LCHR(fmt[e->i]))
		spec_wchar(e, fmt[e->i]);
	else if (CHECK_PRC(fmt[e->i]) || CHECK_LPRC(fmt[e->i]))
		parse_prec(e, fmt[e->i]);
	else if (CHECK_HEX(fmt[e->i]) || CHECK_LHEX(fmt[e->i]))
		process_base(e, fmt[e->i]);
	else if (IN(fmt[e->i]))
		process_return(e);
	else if (fmt[e->i] == 'p' || fmt[e->i] == 'P')
		process_ptraddr(e, fmt[e->i]);
	else if (CHECK_BONUS(fmt[e->i]))
		process_nonprintable(e);
	else if (fmt[e->i] != '\0')
		print_invalid_spec(e, fmt[e->i]);
}

void	check_width(t_pf_env *e)
{
	e->flag.width = va_arg(e->ap[0], int);
	if (e->flag.width < 0)
	{
		e->flag.width = -e->flag.width;
		e->flag.minus = 1;
	}
}

void	check_prec(const char *restrict fmt, t_pf_env *e)
{
	if (e->flag.prec >= 0)
	{
		++e->i;
		return ;
	}
	if (fmt[e->i] == '.' && fmt[e->i + 1] == '*')
	{
		e->flag.prec = va_arg(e->ap[0], int);
		e->i += 2;
	}
	else if (fmt[e->i] == '.')
	{
		++e->i;
		e->flag.prec = ft_atoi(fmt + e->i);
		while (INUM(fmt[e->i]))
			++e->i;
	}
}

void	parse_prec(t_pf_env *e, char type)
{
	long double	ld;
	double		d;

	if (e->mod == pf_L)
	{
		init_long_double(e, &ld);
		if (ld != ld || (ld * 2 == ld && ld != 0))
			return (nan_inf(e, type, ld));
	}
	else
	{
		init_double_argm(e, &d);
		if (d != d || (d * 2 == d && d != 0))
			return (nan_inf(e, type, d));
		ld = (long double)d;
	}
	if (type == 'e' || type == 'E')
		return (print_prec_e(e, ld, type));
	if (type == 'f' || type == 'F')
		return (print_prec_f(e, ld));
	if (type == 'g' || type == 'G')
		return (print_prec_g(e, ld, type));
	if (type == 'a' || type == 'A')
		return (print_prec_a(e, ld, type));
}
