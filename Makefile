# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/15 17:47:09 by msaliuta          #+#    #+#              #
#    Updated: 2019/07/07 20:57:28 by msaliuta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
CMPL	=	gcc
FLGS	=	-Wall -Wextra -Werror
IDIR	=	inc
SDIR	=	src
ODIR	=	obj
SRCS	=	ft_printf\
			parse_mfw\
			int_functs\
			longd_functs\
			process_functs\
			print_functs\
			check_settings\
			ftoa_prec_f\
			init_wstr_arg\
			print_base\
			char_functs\
			print_invalid_spec\
			print_invd_width\
			print_non_printable\
			print_prec_a\
			print_prec_e\
			print_prec_g\
			print_prec_tools\
			print_ptraddr\
			print_str\
			wchar_functs\
			print_wstr

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
