/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:05:29 by msaliuta          #+#    #+#             */
/*   Updated: 2019/06/30 12:05:29 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flag(const char *restrict fmt, t_pf_env *e)
{
	while (ft_strchr(PF_FLAG, fmt[e->i]))
	{
		fmt[e->i] >= 'L' && fmt[e->i] <= 'z' ? get_mod(fmt, e) : 0;
		fmt[e->i] == ' ' ? e->flag.sp = 1 : 0;
		fmt[e->i] == '-' ? e->flag.minus = 1 : 0;
		fmt[e->i] == '+' ? e->flag.plus = 1 : 0;
		fmt[e->i] == '#' ? e->flag.hash = 1 : 0;
		fmt[e->i] == '*' ? get_width(e) : 0;
		fmt[e->i] == '0' ? e->flag.zero = 1 : 0;
		if (fmt[e->i] == '.')
			get_prec(fmt, e);
		else if (fmt[e->i] >= '1' && fmt[e->i] <= '9' && e->flag.prec < 0)
		{
			e->flag.width = ft_atoi(fmt + e->i);
			while (fmt[e->i] >= '0' && fmt[e->i] <= '9')
				++e->i;
		}
		else
			++e->i;
	}
}
