/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:05:38 by msaliuta          #+#    #+#             */
/*   Updated: 2019/06/30 12:05:38 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_tag(const char *restrict fmt, t_pf_env *e)
{
	int	i;
	int tmp;

	init_flag(&e->flag);
	e->mod = pf_nomod;
	e->tag.tag = 0;
	i = 0;
	if (fmt[e->i] >= '0' && fmt[e->i] <= '9')
	{
		tmp = ft_atoi(fmt + e->i);
		while (fmt[e->i + i] >= '0' && fmt[e->i + i] <= '9')
			i++;
		if (fmt[e->i + i] == '$')
		{
			e->tag.tag = 1;
			e->tag.pos = tmp;
			e->i += i + 1;
		}
	}
}
