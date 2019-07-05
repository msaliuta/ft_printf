/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:10 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/03 04:25:10 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_tags(const char *restrict fmt, t_pf_env *e)
{
	int	i;
	int tmp;

	init_flags(&e->flag);
	e->mod = pf_nomod;
	e->tag.tag = 0;
	i = 0;
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
