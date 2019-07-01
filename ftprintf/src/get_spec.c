/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:05:38 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/01 16:39:17 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_spec(const char *restrict fmt, t_pf_env *e)
{
	if (fmt[e->i] == '%')
		spec_percent(e);
	else if ((fmt[e->i] == 'd' || fmt[e->i] == 'i') && e->mod != pf_z)
		spec_int(e);
	else if (fmt[e->i] == 'u' || fmt[e->i] == 'U' || fmt[e->i] == 'D' ||
			((fmt[e->i] == 'd' || fmt[e->i] == 'i') && e->mod == pf_z))
		spec_unsint(e, fmt[e->i]);
	else if ((fmt[e->i] == 'c' || fmt[e->i] == 's') && e->mod != pf_l)
		spec_char(e, fmt[e->i]);
	else if (fmt[e->i] == 'C' || fmt[e->i] == 'S')
		spec_char(e, fmt[e->i] + 32);
	else if (((fmt[e->i] == 'c' || fmt[e->i] == 's') && e->mod == pf_l) ||
			fmt[e->i] == 'C' || fmt[e->i] == 'S')
		spec_wchar(e, fmt[e->i]);
	else if (ft_strchr(PF_PREC, fmt[e->i]))
		spec_precision(e, fmt[e->i]);
	else
		get_spec_01(fmt, e);
}

void	get_spec_01(const char *restrict fmt, t_pf_env *e)
{
	if (ft_strchr(PF_HEX, fmt[e->i]))
		spec_base(e, fmt[e->i]);
	else if (fmt[e->i] == 'n')
		spec_return(e);
	else if (fmt[e->i] == 'p' || fmt[e->i] == 'P')
		spec_ptraddr(e, fmt[e->i]);
	else if (fmt[e->i] == 'r')
		spec_non_printable(e);
	else if (fmt[e->i] == 'w')
		spec_fd(e);
	else if (fmt[e->i] == 'q')
		print_dice(e);
	else if (fmt[e->i] != '\0')
		print_invalid_spec(e, fmt[e->i]);
}
