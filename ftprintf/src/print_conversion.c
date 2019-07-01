/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:06:02 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/01 16:39:20 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_conversion(const char *restrict fmt, t_pf_env *e)
{
	++e->i;
	get_tag(fmt, e);
	get_flag(fmt, e);
	get_spec(fmt, e);
}
