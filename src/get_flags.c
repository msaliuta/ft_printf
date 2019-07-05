/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:08 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/03 04:25:08 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flags(const char *restrict fmt, t_pf_env *e)
{
	while (ft_strchr(IFLAG, fmt[e->i]))
	{
		fmt[e->i] >= 'L' && fmt[e->i] <= 'z' ? get_mods(fmt, e) : 0;
		fmt[e->i] == ' ' ? e->flag.sps = 1 : 0;
		fmt[e->i] == '-' ? e->flag.minus = 1 : 0;
		fmt[e->i] == '+' ? e->flag.plus = 1 : 0;
		fmt[e->i] == '#' ? e->flag.hash = 1 : 0;
		fmt[e->i] == '*' ? get_width(e) : 0;
		fmt[e->i] == '0' ? e->flag.zero = 1 : 0;
		if (fmt[e->i] == '.')
			get_prec(fmt, e);
		else if (INUM1(fmt[e->i]) && e->flag.prec < 0)
		{
			e->flag.width = ft_atoi(fmt + e->i);
			while (INUM(fmt[e->i]))
				++e->i;
		}
		else
			++e->i;
	}
}
