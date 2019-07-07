/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 18:17:20 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/07 20:57:27 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libftprintf/libft.h"
# include <wchar.h>
# include <limits.h>
# include <stdarg.h>

# define CHECK_PCNT(i) (i == '%')
# define FLAGS " 0123456789Lhjltz#*+-."
# define CONV_FLAGS " 0#+-"
# define INUM(i) (i >= '0' && i <= '9')
# define INUM1(i) (i >= '1' && i <= '9')
# define CHECK_BONUS(i) (i == 'r')
# define CHECK_INT(i) (i == 'd' || i == 'i')
# define CHECK_UINT(i) (i == 'u' || i == 'D' || i == 'U')
# define CHECK_CHR(i) (i == 'c' || i == 's')
# define CHECK_LCHR(i) (i == 'C' || i == 'S')
# define CHECK_PRC(i) (i == 'F' || i == 'A' || i == 'G'|| i == 'E')
# define CHECK_LPRC(i) (i == 'f' || i == 'a' || i == 'g'|| i == 'e')
# define CHECK_HEX(i) (i == 'b' || i == 'o' || i == 'x')
# define CHECK_LHEX(i) (i == 'B' || i == 'O' || i == 'X')
# define IN(i) (i == 'n')

typedef struct	s_pf_tag
{
	int			tag;
	int			pos;
}				t_pf_tag;

typedef struct	s_pf_flag
{
	int			sps;
	int			plus;
	int			neg;
	int			minus;
	int			hash;
	int			zero;
	int			prec;
	int			width;
}				t_pf_flag;

typedef enum	e_pf_mod
{
	pf_nomod = 0,
	pf_j,
	pf_z,
	pf_t,
	pf_h,
	pf_hh,
	pf_l,
	pf_ll,
	pf_L
}				t_pf_mod;

typedef	struct	s_pf_env
{
	va_list		ap[2];
	char		*out;
	int			fd;
	int			i;
	t_pf_tag	tag;
	t_pf_flag	flag;
	t_pf_mod	mod;
	int			ret;
}				t_pf_env;
//ft_printf.c
int				ft_printf(const char *restrict frmt, ...);
void			start_fpf(const char *restrict frmt, t_pf_env *o);
void			parse_flags(const char *restrict frmt, t_pf_env *o);
void			check_conv_flag(const char *restrict frmt, t_pf_env *o);
void			parce_modif(const char *restrict frmt, t_pf_env *o);

//parse_mfw.c
void			parse_mfw(const char *restrict fmt, t_pf_env *o);
void			parse_size_spec(const char *restrict fmt, t_pf_env *o);
void			check_width(t_pf_env *o);
void			check_prec(const char *restrict fmt, t_pf_env *o);
void			parse_prec(t_pf_env *o, char type);

//int_funct.c
void			init_long_argm(t_pf_env *o, long *tmp);
void			process_int(t_pf_env *o);
void			init_double_argm(t_pf_env *o, double *tmp);
void			process_unsint(t_pf_env *o, char type);

//longd_funct.c
void			init_long_double(t_pf_env *o, long double *tmp);
void			check_form(t_pf_env *o, long double d, char tnt);
void			process_dgt_sign(t_pf_env *o);
void			process_dgt_prec(t_pf_env *o);

//process_functs.c
void			process_base(t_pf_env *o, char type);
void			process_return(t_pf_env *o);
void			process_ptraddr(t_pf_env *o, char type);
void			process_percent(t_pf_env *o);


//print_functs.c
void			digit_print(t_pf_env *o);
void			base_print(t_pf_env *o, char type, long val);
void			digit_sign_print(t_pf_env *o);
void			base_pre_print(t_pf_env *o, char type, long val);


//print_wids_functs.c
void			print_base_width(t_pf_env *o, char type);
void			print_prec_width(t_pf_env *o);
void			print_digit_width(t_pf_env *o);
void			print_invalid_width(t_pf_env *o);
void			print_ptraddr_width(t_pf_env *o);

void			check_base_prec(t_pf_env *o, char type);

//char_functs.c
void			print_char(t_pf_env *o, char c);
void			init_char_arg(t_pf_env *o, int *tmp);
void			char_for_ptint(t_pf_env *e, int n);
void			spec_char(t_pf_env *o, char type);

//str_functs.c
void			init_str_arg(t_pf_env *o, char **tmp);
void			print_str(t_pf_env *o);
void			str_for_print(t_pf_env *e, int n);
char			*ft_str_prec(char *s1, int dot, int end, int hash);

//wchar_functs.c
void			init_wchar_arg(t_pf_env *o, wchar_t *tmp);
void			print_wchar(t_pf_env *o, wchar_t wc);
void			spec_wchar(t_pf_env *o, char type);
void			print_wchar_minus(t_pf_env *o, wchar_t wc);

//wstr_functs.c
void			print_wstr_minus(t_pf_env *o, wchar_t *wc, int len);
void			print_wstr(t_pf_env *o, wchar_t *wc);
int				get_wstr_len(wchar_t *wc);
void			put_wstr(t_pf_env *o, wchar_t c);
void			put_wstr_c(t_pf_env *o, char c);
void			init_wstr_arg(t_pf_env *o, wchar_t **tmp);


//ftoa_functs.c
void			ftoa_prec_a(t_pf_env *o, double d, char type);
void			ftoa_prec_e(t_pf_env *o, long double d, char type);
void			ftoa_prec_f(t_pf_env *o, long double d);
void			ftoa_prec_eg(t_pf_env *o, long double d, char type, int prec);
void			ftoa_prec_fg(t_pf_env *o, long double d, int end);

long			get_prec_num_e(long double d, int prec);
void			get_exponent(long double d, char type, char **oxpo);

//print_prec_functs.c
void			print_prec_a(t_pf_env *o, double d, char type);
void			print_prec_e(t_pf_env *o, long double d, char type);
void			print_prec_f(t_pf_env *o, long double d);
void			print_prec_g(t_pf_env *o, long double d, char type);
void			print_prec_a_else(t_pf_env *o, double d, char type);


long			get_prec_num_f(long double d, int prec);
void			delete_zero(char *tmp);
void			print_ptraddr(t_pf_env *o, char type);
void			ptraddr_prec(t_pf_env *o);
void			print_invalid_spec(t_pf_env *o, char c);

//bonus_funct.c (process_functs.c nnprtbl)
void			print_twenty_to_thirty(t_pf_env *o, char c);
void			print_ten_to_twenty(t_pf_env *o, char c);
void			print_zero_to_ten(t_pf_env *o, char c);
void			process_nonprintable(t_pf_env *o);

void			check_set(const char *restrict fmt, t_pf_env *o);
void			put_wc(t_pf_env *e, wchar_t c);

void			nan_inf(t_pf_env *o, char type, double var);
char			*ft_ftoa(long double d);
void			hex_prec(t_pf_env *o, double d, char **frac, char type);
void			get_a_expo(double d, char type, char **oxpo);

#endif
