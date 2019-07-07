/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_functs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:20 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/07 16:42:14 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_wchar(t_pf_env *e, char c)
{
	write(e->fd, &c, 1);
}

void	put_wc(t_pf_env *e, wchar_t c)
{
	if (c <= 0x7F)
		put_wchar(e, c);
	else if (c <= 0x7FF)
	{
		put_wchar(e, (c >> 6) + 0xC0);
		put_wchar(e, (c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		put_wchar(e, ((c >> 12) + 0xE0));
		put_wchar(e, ((c >> 6) & 0x3F) + 0x80);
		put_wchar(e, (c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		put_wchar(e, (c >> 18) + 0xF0);
		put_wchar(e, ((c >> 12) & 0x3F) + 0x80);
		put_wchar(e, ((c >> 6) & 0x3F) + 0x80);
		put_wchar(e, (c & 0x3F) + 0x80);
	}
	++e->ret;
}

void	print_wchar(t_pf_env *e, wchar_t wc)
{
	if (e->flag.minus)
	{
		put_wc(e, wc);
		while (e->flag.width-- > 1)
			e->ret += write(e->fd, " ", 1);
	}
	else
	{
		while (e->flag.width-- > 1)
			if (e->flag.zero)
				e->ret += write(e->fd, "0", 1);
			else
				e->ret += write(e->fd, " ", 1);
		put_wc(e, wc);
	}
	++e->i;
}

void	init_wchar_arg(t_pf_env *e, wchar_t *tmp)
{
	if (e->tag.tag)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tag.pos >= 0)
			*tmp = va_arg(e->ap[0], wchar_t);
		return ;
	}
	*tmp = va_arg(e->ap[0], wchar_t);
}

void	spec_wchar(t_pf_env *e, char type)
{
	wchar_t *ws;
	wchar_t wc;

	if (e->flag.minus)
		e->flag.zero = 0;
	if (type == 's' || type == 'S')
	{
		init_wstr_arg(e, &ws);
		if (ws == NULL)
			return (str_for_print(e, 0));
		print_wstr(e, ws);
	}
	else if (type == 'c' || type == 'C')
	{
		init_wchar_arg(e, &wc);
		if (wc == 0)
		{
			char_for_ptint(e, 0);
		}
		print_wchar(e, wc);
	}
}
