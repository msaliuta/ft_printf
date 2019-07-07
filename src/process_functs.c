/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_functs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:25:22 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/07 20:54:01 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_base(t_pf_env *e, char type)
{
	long			tmp;
	unsigned long	val;

	val = 0;
	init_long_argm(e, &tmp);
	if (type == 'O' || e->mod == pf_z || e->mod == pf_t ||
		e->mod == pf_j || e->mod == pf_l || e->mod == pf_ll)
		val = (unsigned long)tmp;
	else if (e->mod == pf_hh)
		val = (unsigned char)tmp;
	else if (e->mod == pf_h)
		val = (unsigned short)tmp;
	else if (e->mod == pf_nomod)
		val = (unsigned int)tmp;
	if (type == 'b' || type == 'B')
		e->out = ft_ultoa_base(val, 2);
	if (type == 'o' || type == 'O')
		e->out = ft_ultoa_base(val, 8);
	if (type == 'x' || type == 'X')
		e->out = ft_ultoa_base(val, 16);
	if (type == 'b' || type == 'o' || type == 'x')
		ft_strlower(e->out);
	e->flag.minus == 1 ? e->flag.zero = 0 : 0;
	base_print(e, type, (long)val);
}

void	process_return(t_pf_env *e)
{
	int	*tmp;

	if (e->tag.tag)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tag.pos >= 0)
			tmp = va_arg(e->ap[0], int *);
	}
	tmp = va_arg(e->ap[0], int *);
	*tmp = e->ret;
	++e->i;
}

void	process_ptraddr(t_pf_env *e, char type)
{
	long			tmp;
	unsigned long	addr;

	init_long_argm(e, &tmp);
	addr = (unsigned long)tmp;
	if (e->flag.prec == 0)
		e->out = ft_strdup("\0");
	else
		e->out = ft_ltoa_base(addr, 16);
	print_ptraddr(e, type);
}

void	process_nonprintable(t_pf_env *e)
{
	char	*tmp;
	int		i;

	init_str_arg(e, &tmp);
	i = -1;
	while (++i < e->flag.width)
	{
		if (tmp[i] >= 0 && tmp[i] <= 10)
			print_zero_to_ten(e, tmp[i]);
		else if (tmp[i] >= 11 && tmp[i] <= 20)
			print_ten_to_twenty(e, tmp[i]);
		else if (tmp[i] >= 21 && tmp[i] <= 31)
			print_twenty_to_thirty(e, tmp[i]);
		++e->ret;
	}
	++e->i;
}

void	process_percent(t_pf_env *e)
{
	if (e->flag.minus)
	{
		e->ret += write(e->fd, "%", 1);
		while (e->flag.width-- > 1)
			e->ret += write(e->fd, " ", 1);
	}
	else
	{
		while (e->flag.width-- > 1)
		{
			if (e->flag.zero)
				e->ret += write(e->fd, "0", 1);
			else
				e->ret += write(e->fd, " ", 1);
		}
		e->ret += write(e->fd, "%", 1);
	}
	++e->i;
}
