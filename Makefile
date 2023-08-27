# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 18:58:34 by jeekpark          #+#    #+#              #
#    Updated: 2023/08/26 15:09:33 by sunwoo-jin       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D
CC				=	cc
CFLAGS			=	-Wall -Wextra -g3 #-Werror -fsanitize=address
HEADER			=	./includes/cub3d.h

SRCS			=	srcs/main.c									\
					srcs/init/init_cub3d.c						\
					srcs/init/init_cub3d_parse.c				\
					srcs/init/line_validation.c					\
					srcs/init/line_validation_map.c				\
					srcs/init/line_validation_rgb.c				\
					srcs/init/line_validation_texture.c			\
					srcs/init/load_images.c						\
					srcs/init/map_validation.c					\
					srcs/utils/rgb8_to_int.c					\
					srcs/utils/set_pixel.c						\
					srcs/utils/exit_game.c						\
					srcs/utils/free_split.c						\
					srcs/utils/free_game.c						\
					srcs/utils/destroy_game.c					\
					srcs/utils/key_press.c						\
					srcs/utils_shape/rect.c						\
					srcs/utils_shape/background_fill.c			\
					srcs/utils_shape/line.c
OBJS			=	$(SRCS:.c=.o)

LIBFT_A			=	srcs/libft/libft.a
LIBMLX_FLAGS	=	-L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	$(MAKE) -C srcs/libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(LIBMLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

clean :
	$(MAKE) -C srcs/libft clean
	rm -rf $(OBJS)

fclean :
	$(MAKE) -C srcs/libft fclean
	rm -rf $(OBJS) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all re clean fclean bonus


# ----- for M1 ----------------------------------------------------------------#
CC_M1				=	arch -x86_64 cc
LIBMLX_M1_FLAGS		=	-L. -lmlx -framework OpenGL -framework Appkit
m1 :
	make CC="$(CC_M1)" LIBMLX_FLAGS="$(LIBMLX_M1_FLAGS)" all
# 제출 전 해야할 것.
# 	1. ./libmlx.dylib 삭제
# 	2. ./includes/mlx.h 삭제
# 	3. 해당 주석 파트 전체 삭제.
#	4. 작동 확인.
# -----------------------------------------------------------------------------#
