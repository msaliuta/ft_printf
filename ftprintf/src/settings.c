/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:06:34 by msaliuta          #+#    #+#             */
/*   Updated: 2019/06/30 14:07:15 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_options(const char *restrict fmt, t_pf_env *e)
{
	if (!ft_strncmp(fmt + e->i, "{SET:BO}", 8))
		e->ret += write(e->fd, "\x1B[1m", 4);
	else if (!ft_strncmp(fmt + e->i, "{SET:FT}", 8))
		e->ret += write(e->fd, "\x1B[2m", 4);
	else if (!ft_strncmp(fmt + e->i, "{SET:IT}", 8))
		e->ret += write(e->fd, "\x1B[3m", 4);
	else if (!ft_strncmp(fmt + e->i, "{SET:UL}", 8))
		e->ret += write(e->fd, "\x1B[4m", 4);
	else if (!ft_strncmp(fmt + e->i, "{SET:BL}", 8))
		e->ret += write(e->fd, "\x1B[5m", 4);
	else if (!ft_strncmp(fmt + e->i, "{SET:RE}", 8))
		e->ret += write(e->fd, "\x1B[7m", 4);
	else if (!ft_strncmp(fmt + e->i, "{SET:CC}", 8))
		e->ret += write(e->fd, "\x1B[8m", 4);
	else if (!ft_strncmp(fmt + e->i, "{SET:RV}", 8))
		e->ret += write(e->fd, "\x1B[28m", 5);
	else
		return ;
	e->i += 8;
}

void	set_bg_colo(const char *restrict fmt, t_pf_env *e)
{
	if (!ft_strncmp(fmt + e->i, "{BGC:BLK}", 9))
		e->ret += write(e->fd, "\x1B[40m", 5);
	else if (!ft_strncmp(fmt + e->i, "{BGC:RED}", 9))
		e->ret += write(e->fd, "\x1B[41m", 5);
	else if (!ft_strncmp(fmt + e->i, "{BGC:GRN}", 9))
		e->ret += write(e->fd, "\x1B[42m", 5);
	else if (!ft_strncmp(fmt + e->i, "{BGC:YEL}", 9))
		e->ret += write(e->fd, "\x1B[43m", 5);
	else if (!ft_strncmp(fmt + e->i, "{BGC:BLU}", 9))
		e->ret += write(e->fd, "\x1B[44m", 5);
	else if (!ft_strncmp(fmt + e->i, "{BGC:MGT}", 9))
		e->ret += write(e->fd, "\x1B[45m", 5);
	else if (!ft_strncmp(fmt + e->i, "{BGC:CYN}", 9))
		e->ret += write(e->fd, "\x1B[46m", 5);
	else if (!ft_strncmp(fmt + e->i, "{BGC:WHT}", 9))
		e->ret += write(e->fd, "\x1B[47m", 5);
	else
		return ;
	e->i += 9;
}

void	set_light_colo(const char *restrict fmt, t_pf_env *e)
{
	if (!ft_strncmp(fmt + e->i, "{LT:BLK}", 8))
		e->ret += write(e->fd, "\x1B[90m", 5);
	else if (!ft_strncmp(fmt + e->i, "{LT:RED}", 8))
		e->ret += write(e->fd, "\x1B[91m", 5);
	else if (!ft_strncmp(fmt + e->i, "{LT:GRN}", 8))
		e->ret += write(e->fd, "\x1B[92m", 5);
	else if (!ft_strncmp(fmt + e->i, "{LT:YEL}", 8))
		e->ret += write(e->fd, "\x1B[93m", 5);
	else if (!ft_strncmp(fmt + e->i, "{LT:BLU}", 8))
		e->ret += write(e->fd, "\x1B[94m", 5);
	else if (!ft_strncmp(fmt + e->i, "{LT:MGT}", 8))
		e->ret += write(e->fd, "\x1B[95m", 5);
	else if (!ft_strncmp(fmt + e->i, "{LT:CYN}", 8))
		e->ret += write(e->fd, "\x1B[96m", 5);
	else if (!ft_strncmp(fmt + e->i, "{LT:WHT}", 8))
		e->ret += write(e->fd, "\x1B[97m", 5);
	else
		return ;
	e->i += 8;
}

void	set_colo(const char *restrict fmt, t_pf_env *e)
{
	if (!ft_strncmp(fmt + e->i, "{BLK}", 5))
		e->ret += write(e->fd, "\x1B[30m", 5);
	else if (!ft_strncmp(fmt + e->i, "{RED}", 5))
		e->ret += write(e->fd, "\x1B[31m", 5);
	else if (!ft_strncmp(fmt + e->i, "{GRN}", 5))
		e->ret += write(e->fd, "\x1B[32m", 5);
	else if (!ft_strncmp(fmt + e->i, "{YEL}", 5))
		e->ret += write(e->fd, "\x1B[33m", 5);
	else if (!ft_strncmp(fmt + e->i, "{BLU}", 5))
		e->ret += write(e->fd, "\x1B[34m", 5);
	else if (!ft_strncmp(fmt + e->i, "{MGT}", 5))
		e->ret += write(e->fd, "\x1B[35m", 5);
	else if (!ft_strncmp(fmt + e->i, "{CYN}", 5))
		e->ret += write(e->fd, "\x1B[36m", 5);
	else if (!ft_strncmp(fmt + e->i, "{WHT}", 5))
		e->ret += write(e->fd, "\x1B[37m", 5);
	else
		return ;
	e->i += 5;
}
