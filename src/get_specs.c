/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:10 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/03 06:09:53 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_specs(const char *restrict fmt, t_pf_env *e)
{
	if (fmt[e->i] == '%')
		sp_percent(e);
	else if (IINT(fmt[e->i]) && e->mod != pf_z)
		spec_int(e);
	else if (IUINT(fmt[e->i]) || (IINT(fmt[e->i]) && e->mod == pf_z))
		spec_unsint(e, fmt[e->i]);
	else if (ICHR(fmt[e->i]) && e->mod != pf_l)
		spec_char(e, fmt[e->i]);
	else if (ILCHR(fmt[e->i]))
		spec_char(e, fmt[e->i] + 32);
	else if ((ICHR(fmt[e->i]) && e->mod == pf_l) ||
			ILCHR(fmt[e->i]))
		spec_wchar(e, fmt[e->i]);
	else if (IPRC(fmt[e->i]) || ILPRC(fmt[e->i]))
		spec_precision(e, fmt[e->i]);
	else
		get_specs_01(fmt, e);
}

void	get_specs_01(const char *restrict fmt, t_pf_env *e)
{
	if (IHEX(fmt[e->i]) || ILHEX(fmt[e->i]))
		spec_base(e, fmt[e->i]);
	else if (IN(fmt[e->i]))
		spec_return(e);
	else if (fmt[e->i] == 'p' || fmt[e->i] == 'P')
		spec_ptraddr(e, fmt[e->i]);
	else if (fmt[e->i] == 'r')
		spec_non_printable(e);
	else if (fmt[e->i] == 'q')
		print_dice(e);
	else if (fmt[e->i] != '\0')
		print_invalid_spec(e, fmt[e->i]);
}
