/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:21 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/08 13:16:18 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_wstr(t_pf_env *e, wchar_t c)
{
	if (c <= 0x7F)
		prrint_wstr_1(e, c);
	else if (c <= 0x7FF)
	{
		prrint_wstr_1(e, (c >> 6) + 0xC0);
		prrint_wstr_1(e, (c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		prrint_wstr_1(e, ((c >> 12) + 0xE0));
		prrint_wstr_1(e, ((c >> 6) & 0x3F) + 0x80);
		prrint_wstr_1(e, (c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		prrint_wstr_1(e, (c >> 18) + 0xF0);
		prrint_wstr_1(e, ((c >> 12) & 0x3F) + 0x80);
		prrint_wstr_1(e, ((c >> 6) & 0x3F) + 0x80);
		prrint_wstr_1(e, (c & 0x3F) + 0x80);
	}
}

int		get_wstr_len(wchar_t *wchr)
{
	int i;
	int len;

	i = -1;
	len = 0;
	while (wchr[++i] != 0)
	{
		if (wchr[i] <= 0x7F)
			len++;
		else if (wchr[i] <= 0x7FF)
			len += 2;
		else if (wchr[i] <= 0xFFFF)
			len += 3;
		else if (wchr[i] <= 0x10FFFF)
			len += 4;
	}
	return (len);
}

void	wstr_min_print(t_pf_env *e, wchar_t *wchr, int len)
{
	int i;

	i = -1;
	if (e->flag.prec >= 0)
	{
		while (wchr[++i] != 0 && i < e->flag.prec)
			check_wstr(e, wchr[i]);
	}
	else
	{
		while (wchr[++i] != 0)
			check_wstr(e, wchr[i]);
	}
	while (e->flag.width-- > len)
		if (e->flag.zero == 1)
			e->ret = write (e->fd, "0", 1);
		else
			e->ret = write (e->fd, " ", 1);
}

void	wstr_init(t_pf_env *e, wchar_t **tmp)
{
	if (e->tag.tag)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tag.pos >= 0)
			*tmp = va_arg(e->ap[0], wchar_t *);
		return ;
	}
	*tmp = va_arg(e->ap[0], wchar_t *);
}

void	print_wstr(t_pf_env *e, wchar_t *wchr)
{
	int i;
	int len;

	i = -1;
	if (e->flag.prec < 0)
		len = get_wstr_len(wchr);
	else
		len = e->flag.prec;
	if (e->flag.minus)
		wstr_min_print(e, wchr, len);
	else
	{
		while (e->flag.width-- > len)
			e->ret += (e->flag.zero == 1 ?
			write(e->fd, "0", 1) : write(e->fd, " ", 1));
		if (e->flag.prec >= 0)
			while (wchr[++i] != 0 && i * 4 < e->flag.prec)
				check_wstr(e, wchr[i]);
		else
			while (wchr[++i] != 0)
				check_wstr(e, wchr[i]);
	}
	++e->i;
}
