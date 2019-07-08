/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_functs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:20 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/08 13:16:49 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prrint_wchar_1(t_pf_env *e, char c)
{
	write(e->fd, &c, 1);
}

void	check_wchar(t_pf_env *e, wchar_t c)
{
	if (c <= 0x7F)
		prrint_wchar_1(e, c);
	else if (c <= 0x7FF)
	{
		prrint_wchar_1(e, (c >> 6) + 0xC0);
		prrint_wchar_1(e, (c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		prrint_wchar_1(e, ((c >> 12) + 0xE0));
		prrint_wchar_1(e, ((c >> 6) & 0x3F) + 0x80);
		prrint_wchar_1(e, (c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		prrint_wchar_1(e, (c >> 18) + 0xF0);
		prrint_wchar_1(e, ((c >> 12) & 0x3F) + 0x80);
		prrint_wchar_1(e, ((c >> 6) & 0x3F) + 0x80);
		prrint_wchar_1(e, (c & 0x3F) + 0x80);
	}
	++e->ret;
}

void	print_wchar(t_pf_env *e, wchar_t wc)
{
	if (e->flag.minus)
	{
		check_wchar(e, wc);
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
		check_wchar(e, wc);
	}
	++e->i;
}

void	wchar_init(t_pf_env *e, wchar_t *tmp)
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

void	process_wchar(t_pf_env *e, char type)
{
	wchar_t *ws;
	wchar_t wc;

	if (e->flag.minus)
		e->flag.zero = 0;
	if (type == 's' || type == 'S')
	{
		wstr_init(e, &ws);
		if (ws == NULL)
			return (str_for_print(e, 0));
		print_wstr(e, ws);
	}
	else if (type == 'c' || type == 'C')
	{
		wchar_init(e, &wc);
		if (wc == 0)
		{
			char_for_ptint(e, 0);
		}
		print_wchar(e, wc);
	}
}
