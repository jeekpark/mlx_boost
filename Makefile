# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 14:55:02 by jeekpark          #+#    #+#              #
#    Updated: 2023/11/01 15:57:17 by jeekpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -fPIC
LDFLAGS		=	-dynamiclib
SRCS		=	srcs/mlx_boost/boost_init.c					\
				srcs/mlx_boost/boost_loop.c					\
				srcs/mlx_boost/boost_add_component.c		\
				srcs/mlx_boost/boost_component_to_window.c	\
				srcs/mlx_boost_utils/boost_set_pixel.c		\
				srcs/mlx_boost_utils/boost_strdup.c			\
				srcs/mlx_boost_list/boost_list_init.c		
				
OBJS		=	$(SRCS:.c=.o)

LIBMLX		=	./mlx/libmlx.dylib
LIBMLXBOOST	=	libmlxboost.dylib

all : $(LIBMLXBOOST)


$(LIBMLXBOOST): $(OBJS)
	make -C mlx 2>/dev/null 1>/dev/null
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBMLX)


%.o : %.cc
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make -C mlx clean
	rm -f $(OBJS) $(LIBMLXBOOST)


.PHONY: all clean