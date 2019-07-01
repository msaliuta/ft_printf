/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:05:29 by msaliuta          #+#    #+#             */
/*   Updated: 2019/06/30 12:13:09 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_mod(const char *restrict fmt, t_pf_env *e)
{
	if (fmt[e->i] == 'h' && fmt[e->i + 1] != 'h' && e->mod == pf_nomod)
		e->mod = pf_h;
	else if (fmt[e->i] == 'h' && fmt[e->i + 1] == 'h' && e->mod == pf_nomod)
	{
		e->mod = pf_hh;
		++e->i;
	}
	else if (fmt[e->i] == 'l' && fmt[e->i + 1] != 'l')
		e->mod = pf_l;
	else if (fmt[e->i] == 'l' && fmt[e->i + 1] == 'l')
	{
		e->mod = pf_ll;
		++e->i;
	}
	else if (fmt[e->i] == 'z')
		e->mod = pf_z;
	else if (fmt[e->i] == 'j')
		e->mod = pf_j;
	else if (fmt[e->i] == 'L')
		e->mod = pf_L;
	else if (fmt[e->i] == 't')
		e->mod = pf_t;
}
