/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:06:45 by msaliuta          #+#    #+#             */
/*   Updated: 2019/06/30 14:12:09 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_settings(const char *restrict fmt, t_pf_env *e)
{
	int tmp;

	tmp = e->i;
	if (!ft_strncmp(fmt + e->i, "{OFF}", 5))
	{
		e->ret += write(e->fd, "\x1B[0m", 4);
		e->i += 5;
		return ;
	}
	else if (!ft_strncmp(fmt + e->i, "{SET:", 5))
		set_options(fmt, e);
	else if (!ft_strncmp(fmt + e->i, "{BGC:", 5))
		set_bg_colo(fmt, e);
	else if (!ft_strncmp(fmt + e->i, "{LT:", 4))
		set_light_colo(fmt, e);
	else
		set_colo(fmt, e);
	if (tmp == e->i)
		e->ret += write(e->fd, &fmt[e->i++], 1);
}
