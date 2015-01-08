#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/26 19:03:08 by tfleming          #+#    #+#              #
#    Updated: 2014/12/28 18:15:10 by tfleming         ###   ########.fr        #
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
				print_conversion.o \
				print_signed_decimal.o \
				print_format_error.o \
				get_current.o

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

