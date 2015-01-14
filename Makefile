#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/26 19:03:08 by tfleming          #+#    #+#              #
#    Updated: 2015/01/13 14:12:55 by tfleming         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =			libftprintf.a

CC =			gcc
FLAGS =			-Wall -Werror -Wextra -g
LIBFT =			"libft/"

COMPILED =		ft_printf.o \
				handle_format.o \
				parse_conversion.o \
				parse_flags.o \
				parse_width.o \
				parse_precision.o \
				parse_length.o \
				parse_specifier.o \
				validate_conversion.o \
				validate_flags.o \
				print_conversion.o \
				print_format_error.o \
				get_current.o \
				get_number_argument.o \
				get_unsigned_number_argument.o \
				get_string_decimal.o \
				get_string_string.o \
				get_string_pointer.o \
				get_string_octal.o \
				get_string_hex.o

all: $(NAME)

$(NAME): makelibft $(COMPILED)
	@cp $(LIBFT)libft.a .
	@mv libft.a $(NAME)
	@ar rc $(NAME) $(COMPILED)
	@ranlib $(NAME)
	@echo "made" $(NAME)

makelibft:
	@make -C $(LIBFT)

$(COMPILED): %.o: %.c
	@$(CC) -c $(FLAGS) -I $(LIBFT) $< -o $@ #-L $(LIBFT) -lft 

clean:
	@make -C $(LIBFT) clean
	@-/bin/rm -f $(COMPILED)
	@echo "cleaned" $(NAME)

fclean: clean
	@make -C $(LIBFT) fclean
	@-/bin/rm -f $(NAME)
	@echo "fcleaned" $(NAME)

re: fclean all

