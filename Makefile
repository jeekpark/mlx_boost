# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 14:55:02 by jeekpark          #+#    #+#              #
#    Updated: 2023/11/01 22:06:02 by jeekpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC								=	cc
CFLAGS							=	-Wall -Wextra -Werror -fPIC
LDFLAGS							=	-dynamiclib


MLX_BOOST_DIR					=	./srcs/mlx_boost/
MLX_BOOST_LIST_DIR				=	./srcs/mlx_boost_list/
MLX_BOOST_UTILS_DIR				=	./srcs/mlx_boost_utils/

MLX_BOOST_FILE_NAME				=	boost_init.c						\
									boost_loop.c						

MLX_BOOST_LIST_FILE_NAME		=	boost_list_del_all_node.c			\
									boost_list_del_one_node.c			\
									boost_list_init.c					\
									boost_list_push_back.c

MLX_BOOST_UTILS_FILE_NAME		=	boost_set_pixel.c					\
									boost_strdup.c


MLX_BOOST_SRCS 					=	$(addprefix $(MLX_BOOST_DIR), $(MLX_BOOST_FILE_NAME))
MLX_BOOST_LIST_SRCS				=	$(addprefix $(MLX_BOOST_LIST_DIR), $(MLX_BOOST_LIST_FILE_NAME))
MLX_BOOST_UTILS_SRCS			=	$(addprefix $(MLX_BOOST_UTILS_DIR), $(MLX_BOOST_UTILS_FILE_NAME))


MLX_BOOST_OBJS					=	$(MLX_BOOST_SRCS:.c=.o)
MLX_BOOST_LIST_OBJS				=	$(MLX_BOOST_LIST_SRCS:.c=.o)
MLX_BOOST_UTILS_OBJS			=	$(MLX_BOOST_UTILS_SRCS:.c=.o)




LIBMLXBOOST						=	libmlxboost.dylib

ARCH		:= $(shell uname -m)
ARCH_M1		=	arm64
ifeq ($(ARCH),$(ARCH_M1))
	LIBMLX = ./mlx_m1/libmlx.dylib
else
	LIBMLX = ./mlx_intel/libmlx.dylib
endif


all : $(LIBMLXBOOST)


$(LIBMLXBOOST): $(MLX_BOOST_OBJS) $(MLX_BOOST_LIST_OBJS) $(MLX_BOOST_UTILS_OBJS)
ifeq ($(ARCH),$(ARCH_M1))
	make -C mlx_m1 2>/dev/null 1>/dev/null
else
	make -C mlx_intel 2>/dev/null 1>/dev/null
endif
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBMLX)


%.o : %.cc
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make -C mlx_m1 clean
	rm -f $(MLX_BOOST_OBJS) $(MLX_BOOST_LIST_OBJS) $(MLX_BOOST_UTILS_OBJS) $(LIBMLXBOOST)


.PHONY: all clean