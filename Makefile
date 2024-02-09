
# Project
NAME = cub3D
NAME_BONUS = cub3D_bonus

# Compiler
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -MMD -MP -Ofast -ffast-math -g3

# Paths
SRC_PATH = ./src/
BIN_PATH = ./bin/
MLX_PATH = ./minilibx-linux/

# Includes
MLX			= libmlx.a
LIBFT		= libft/libft.a
INCLUDES	= include/

# Clean
RM	= rm -rf

# Files
SRC =	main.c \
		setup_mlx.c \
		draw.c \
		fill_map_file_1.c \
		fill_map_file_2.c \
		fill_map_file_3.c \
		parse_utils_1.c \
		parse_utils_2.c \
		render_1.c \
		render_2.c \
		setup_data_null.c \
		mlx_key_events.c \
		mlx_mouse_events.c \
		cleaning.c \
		cleaning_utils.c \
		move.c \
		move_longitudinal.c \
		move_sideways.c \
		mlx_utils.c \
		setup_game.c \
		checkup_map_1.c \
		checkup_map_2.c \

SRC_BONUS = bonus_doors.c \
			bonus_draw_dialog_box.c \
			bonus_draw_protagonists.c \
			bonus_minimap.c \
			bonus_draw.c \
			bonus_draw_things.c \
			bonus_fill_img_1.c \
			bonus_fill_img_2.c \
			bonus_fill_img_3.c \
			bonus_fill_img_4.c \
			bonus_main.c \
			bonus_render_1.c \
			bonus_render_back.c \
			bonus_mlx_utils.c \
			bonus_collectibles.c \
			bonus_summon_cheshire_cat.c \
			bonus_time.c \
			checkup_map_1.c \
			bonus_checkup_map_2.c \
			cleaning.c \
			cleaning_utils.c \
			fill_map_file_1.c \
			fill_map_file_2.c \
			fill_map_file_3.c \
			mlx_key_events.c \
			mlx_mouse_events.c \
			mlx_utils.c \
			move_longitudinal.c \
			move_sideways.c \
			move.c \
			parse_utils_1.c \
			parse_utils_2.c \
			render_2.c \
			setup_data_null.c \
			setup_game.c \
			setup_mlx.c \
			bonus_setup.c \

# Object files
OBJ			= $(addprefix $(BIN_PATH), $(SRC:.c=.o))
OBJ_BONUS	= $(addprefix $(BIN_PATH), $(SRC_BONUS:.c=.o))
# OBJ_BONUS		= $(addprefix $(BIN_PATH), $(SRC_BONUS:.c=.o))
DEPS	= $(OBJ:.o=.d) $(OBJ_BONUS:.o=.d)

all : ${NAME}

.c.o :	
		${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o ${<:.c=.o}

$(BIN_PATH)%.o: $(SRC_PATH)%.c
		mkdir -p $(dir $@)
		@ $(CC) $(CFLAGS) -c $< -o $@

${NAME} : ${OBJ}
		make all -C libft
		make -sC $(MLX_PATH)
		${CC} -o ${NAME} -g ${CFLAGS} ${OBJ} ${LIBFT} ${MLX_PATH}${MLX} -lXext -lX11 -lm
		@clear
		@toilet --gay "cub3D"


${NAME_BONUS} : ${NAME} ${OBJ_BONUS}
		make all -C libft
		make -sC $(MLX_PATH)
		${CC} -o ${NAME_BONUS} -g ${CFLAGS} ${OBJ_BONUS} ${LIBFT} ${MLX_PATH}${MLX} -lXext -lX11 -lm
		@clear
		@toilet --gay "welcome to wonderland!"
	
bonus: $(NAME_BONUS)
	
clean :
		${RM} ${BIN_PATH}
		make clean -sC ${MLX_PATH}
		make clean -C libft

fclean : clean
		make fclean -C libft
		${RM} ${NAME} ${NAME_BONUS}
		@clear

re :		fclean all

.PHONY :	all clean fclean re

-include $(DEPS)