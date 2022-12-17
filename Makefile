# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhihao <zhihao@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 16:41:49 by zhihao            #+#    #+#              #
#    Updated: 2022/12/17 18:03:49 by zhihao           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

INCLUDE = -I ./include/

CFLAGS = -Wall -Wextra -Werror $(INCLUDE)

RM = rm -rf 

SRCDIR = ./src/

SRCNAME = ft_printf.c\
			ft_printf_%_.c\
			ft_printf_d_i_.c\
			ft_printf_p_.c\
			ft_printf_s_.c\
			ft_printf_u_.c\
			ft_printf_x_X_.c\
			ft_itoa.c

SRCS = $(addprefix $(SRCDIR),$(SRCNAME))

OBJS = $(SRCS:.c=.o)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

all:		$(NAME)

clean:		
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

main:			
			gcc -Wall -Wextra -Werror main.c libftprintf.a
			./a.out

.RHONY:		all clean fclean re