# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 14:55:02 by jeekpark          #+#    #+#              #
#    Updated: 2023/11/01 00:21:28 by jeekpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -fPIC
LDFLAGS		=	-shared
SRCS		=	srcs/mlx_boost/boost_init.c					\
				srcs/mlx_boost/boost_loop.c					\
				srcs/mlx_boost_utils/boost_set_pixel.c		\
				srcs/mlx_boost_list/boost_list_init.c
OBJS		=	$(SRCS:.c=.o)

LIBMLX		=	./mlx/libmlx.dylib
LIBMLXBOOST	=	libmlxboost.dylib

all : $(LIBMLXBOOST)


$(LIBMLXBOOST): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBMLX)


%.o : %.cc
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS) $(LIBMLXBOOST)


.PHONY: all clean