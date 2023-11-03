NAME			=	test

CC				=	cc
CFLAGS			=	
HEADER			=	./includes/

SRCS			=	test.c

OBJS			=	$(SRCS:.c=.o)

LIBMLX_FLAGS	=	-L. -lmlxboost -lmlx -framework OpenGL -framework Appkit

all : $(NAME)


$(NAME) : $(OBJS)
	cp ../libmlxboost.dylib ./libmlxboost.dylib
	cp ../mlx_apple/libmlx.dylib ./libmlx.dylib
	$(CC) $(CFLAGS) -I $(HEADER) $(OBJS) $(LIBMLX_FLAGS) -o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

fclean :
	rm -rf $(OBJS) $(NAME) lib*

re :
	make fclean
	make all