/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:05:39 by msaliuta          #+#    #+#             */
/*   Updated: 2019/06/30 12:05:39 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_width(t_pf_env *e)
{
	e->flag.width = va_arg(e->ap[0], int);
	if (e->flag.width < 0)
	{
		e->flag.width = -e->flag.width;
		e->flag.minus = 1;
	}
}
