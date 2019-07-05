/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_fpf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 07:06:53 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/03 07:46:48 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	work_fpf(const char *restrict fmt, t_pf_env *e)
{
	while (fmt[e->i])
	{
		if (fmt[e->i] == '{')
			check_set(fmt, e);
		else if (IPRSNT(fmt[e->i]) && !fmt[e->i + 1])
		{
			e->ret = 0;
			break ;
		}
		else if (IPRSNT(fmt[e->i]) && !IPRSNT(fmt[e->i + 1]))
		{
			++e->i;
			get_tags(fmt, e);
			get_flags(fmt, e);
			get_specs(fmt, e);
		}
		else if (IPRSNT(fmt[e->i]) && IPRSNT(fmt[e->i + 1]))
		{
			e->ret += write(e->fd, "%", 1);
			e->i += 2;
		}
		else
			e->ret += write(e->fd, &fmt[e->i++], 1);
	}
}

void	init_flags(t_pf_flag *flag)
{
	flag->sps = 0;
	flag->plus = 0;
	flag->neg = 0;
	flag->minus = 0;
	flag->hash = 0;
	flag->zero = 0;
	flag->prec = -1;
	flag->width = 0;
}
