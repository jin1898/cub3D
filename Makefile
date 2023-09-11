# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 18:58:34 by jeekpark          #+#    #+#              #
#    Updated: 2023/09/11 15:26:42 by jsunwoo          ###   ########.fr        #
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
					srcs/init/line_validation_rgb_to_int.c		\
					srcs/init/line_validation_texture.c			\
					srcs/init/load_images.c						\
					srcs/init/map_validation.c					\
					srcs/init/map_validation_dfs.c				\
					srcs/init/map_validation_is_surround.c		\
					srcs/loop/key_press.c						\
					srcs/loop/key_release.c						\
					srcs/loop/mouse_move.c						\
					srcs/loop/loop_hook.c						\
					srcs/loop/reset_vector.c					\
					srcs/render/render_mini_map.c				\
					srcs/render/render_game_scene.c				\
					srcs/utils/exit_game.c						\
					srcs/utils/free_split.c						\
					srcs/utils/free_game.c						\
					srcs/utils/destroy_instance.c				\
					srcs/utils/trash.c							\
					srcs/utils_draw/draw_line_to_img.c			\
					srcs/utils_draw/draw_pixel_to_img.c			\
					srcs/utils_draw/draw_rect_to_img.c			\
					srcs/utils_draw/set_pixel.c					\
					srcs/utils_draw/rgb8_to_int.c				\
					srcs/utils_math/add_vector.c				\
					srcs/utils_math/deg_to_rad.c				\
					srcs/utils_math/rotate_vector.c				\
					srcs/utils_math/substract_vector.c			\
					srcs/utils_math/set_vector.c				\
					srcs/utils_math/move_vector.c				\


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
