# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/15 17:47:09 by msaliuta          #+#    #+#              #
#    Updated: 2019/07/01 16:47:29 by msaliuta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
CMPL	=	gcc
FLGS	=	-Wall -Wextra -Werror
IDIR	=	inc
SDIR	=	src
ODIR	=	obj
SRCS	=	ft_atoi\
			ft_bzero\
			ft_itoa\
			ft_itoa_base\
			ft_ltoa\
			ft_ltoa_base\
			ft_printf\
			ft_strchr\
			ft_strcpy\
			ft_strdup\
			ft_strjoin\
			ft_strlen\
			ft_strlower\
			ft_strncmp\
			ft_strnew\
			ft_strsub\
			ft_uitoa\
			ft_uitoa_base\
			ft_ultoa\
			ft_ultoa_base\
			print_base\
			print_char\
			print_dice\
			print_digit\
			print_invalid\
			print_non_printable\
			print_prec_a\
			print_prec_e\
			print_prec_f\
			print_prec_g\
			print_prec_tools\
			print_ptraddr\
			print_str\
			print_wchar\
			print_wstr\
			print_conversion\
			settings\
			check_settings\
			get_tag\
			get_mod\
			get_flag\
			get_spec\
			get_prec\
			get_width\
			spec_int\
			spec_persent\
			spec_unsint\
			spec_wchar\
			spec_char\
			spec_precision\
			spec_base\
			spec_ptraddr\
			spec_return\
			spec_non_printable\
			spec_fd\
			print_invalid_spec\
			init_long_double\
			init_char_arg\
			init_str_arg\
			init_int_arg\
			init_prec_arg\
			init_wchar_arg\
			init_wstr_arg\
			settings\
			get_prec_num_f\
			ftoa_prec_f

CSRC	=	$(addprefix $(SDIR)/, $(addsuffix .c, $(SRCS)))
COBJ	=	$(addprefix $(ODIR)/, $(addsuffix .o, $(SRCS)))

all: $(NAME)

$(NAME): $(COBJ)
	@ar rc $(NAME) $(COBJ)
	@echo "\n$(NAME) created"

$(ODIR)/%.o: $(SDIR)/%.c | $(ODIR)
	@$(CMPL) -o $@ -c $< $(FLGS) -I$(IDIR)
	@echo ".\c"

$(ODIR):
	@mkdir $(ODIR)
	@echo "preparing \c"

clean:
	@rm -rf $(ODIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all fclean re clean
