# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/15 17:47:09 by msaliuta          #+#    #+#              #
#    Updated: 2019/07/07 14:39:11 by msaliuta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
CMPL	=	gcc
FLGS	=	-Wall -Wextra -Werror
IDIR	=	inc
SDIR	=	src
ODIR	=	obj
SRCS	=	check_settings\
			main\
			parse_mfw\
			ftoa_prec_f\
			get_prec_num_f\
			init_char_arg\
			init_int_arg\
			init_long_double\
			init_prec_arg\
			init_str_arg\
			init_wchar_arg\
			init_wstr_arg\
			print_base\
			print_char\
			print_digit\
			print_invalid_spec\
			print_invd_width\
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
			spec_base\
			spec_fd\
			spec_non_printable\
			spec_persent\
			spec_precision\
			spec_ptraddr\
			spec_return\
			spec_wchar

CSRC	=	$(addprefix $(SDIR)/, $(addsuffix .c, $(SRCS)))
COBJ	=	$(addprefix $(ODIR)/, $(addsuffix .o, $(SRCS)))

all: $(NAME)

$(NAME): $(COBJ)
	@make -C ./libftprintf
	@cp ./libftprintf/libft.a ./$(NAME)
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
	@make -C ./libftprintf clean

fclean: clean
	@rm -rf $(NAME)
	@make -C ./libftprintf fclean

re: fclean all

.PHONY: all fclean re clean
