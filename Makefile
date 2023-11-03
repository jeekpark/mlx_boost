# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 14:55:02 by jeekpark          #+#    #+#              #
#    Updated: 2023/11/03 16:42:45 by jeekpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME							:=	libmlxboost.dylib

CC								:=	cc
CFLAGS							:=	-Wall -Wextra -Werror -fPIC
LDFLAGS							:=	-dynamiclib

MLX_BOOST_DIR					:=	./srcs/mlx_boost/
MLX_BOOST_LIST_DIR				:=	./srcs/mlx_boost_list/
MLX_BOOST_UTILS_DIR				:=	./srcs/mlx_boost_utils/

MLX_BOOST_FILE_NAME				:=	boost_init.c						\
									boost_loop.c						\
									boost_add_component.c				\
									boost_component_to_window.c			\
									boost_draw_pixel_to_compnent.c		\
									boost_del_component_by_name.c		\
									boost_destroy.c

MLX_BOOST_LIST_FILE_NAME		:=	boost_list_del_all_node.c			\
									boost_list_del_one_node.c			\
									boost_list_init.c					\
									boost_list_push_back.c

MLX_BOOST_UTILS_FILE_NAME		:=	boost_set_pixel.c					\
									boost_strdup.c						\
									boost_del_component.c


MLX_BOOST_SRCS 					:=	$(addprefix $(MLX_BOOST_DIR), $(MLX_BOOST_FILE_NAME))
MLX_BOOST_LIST_SRCS				:=	$(addprefix $(MLX_BOOST_LIST_DIR), $(MLX_BOOST_LIST_FILE_NAME))
MLX_BOOST_UTILS_SRCS			:=	$(addprefix $(MLX_BOOST_UTILS_DIR), $(MLX_BOOST_UTILS_FILE_NAME))


MLX_BOOST_OBJS					:=	$(MLX_BOOST_SRCS:.c=.o)
MLX_BOOST_LIST_OBJS				:=	$(MLX_BOOST_LIST_SRCS:.c=.o)
MLX_BOOST_UTILS_OBJS			:=	$(MLX_BOOST_UTILS_SRCS:.c=.o)

ARCH							:=	$(shell uname -m)
ARCH_ARM64						:=	arm64

LIBMLX_APPLE_DIR				:=	./mlx_arm64/
LIBMLX_INTEL_DIR				:=	./mlx_x86_64/

LIBMLX_FILE_NAME				:=	libmlx.dylib

ifeq ($(ARCH), $(ARCH_ARM64))
LIBMLX							=	$(addprefix $(LIBMLX_APPLE_DIR), $(LIBMLX_FILE_NAME))
else
LIBMLX							=	$(addprefix $(LIBMLX_INTEL_DIR), $(LIBMLX_FILE_NAME))
endif

MAKE_SINGLE_THREAD				:=	make -j 1
STDOUT_SKIP						:=	1>/dev/null
STDERR_SKIP						:=	2>/dev/null

all : $(NAME)

$(NAME): $(MLX_BOOST_OBJS) $(MLX_BOOST_LIST_OBJS) $(MLX_BOOST_UTILS_OBJS)
ifeq ($(ARCH), $(ARCH_ARM64))
	$(MAKE_SINGLE_THREAD) -C $(LIBMLX_APPLE_DIR) $(STDOUT_SKIP) $(STDERR_SKIP)
else
	$(MAKE_SINGLE_THREAD) -C $(LIBMLX_INTEL_DIR) $(STDOUT_SKIP) $(STDERR_SKIP)
endif
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBMLX)

%.o : %.cc
	$(CC) $(CFLAGS) -c $< -o $@

clean :
ifeq ($(ARCH), $(ARCH_ARM64))
	$(MAKE_SINGLE_THREAD) -C $(LIBMLX_APPLE_DIR) clean
else
	$(MAKE_SINGLE_THREAD) -C $(LIBMLX_INTER_DIR) clean
endif
	$(RM) $(MLX_BOOST_OBJS) $(MLX_BOOST_LIST_OBJS) $(MLX_BOOST_UTILS_OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re