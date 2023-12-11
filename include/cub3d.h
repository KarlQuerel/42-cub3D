
#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx_int.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/include/libft.h"

# define MOVE_SPEED	0.4
# define ROT_SPEED	0.2 // peut etre plus precis

// handle window
# define IMG_WIDTH	640
# define IMG_HEIGHT	640
# define EXIT		17
# define KEY_ESC	65307


# define UP		65362
# define DOWN	65364
# define RIGHT	65363
# define LEFT	65361

# define UP_W		119
# define DOWN_S		115
# define RIGHT_D	100
# define LEFT_A		97

typedef float	t_v2f __attribute__((vector_size (8)));
// typedef enum e_xyz {x, y}	t_xy;

enum e_parse
{
	NORTH = 1,
	SOUTH,
	WEST,
	EAST,
	OUT,
	PLAYER,
	MAP,
};

typedef struct s_img_info
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}	t_img_info;

typedef struct s_data
{
	// window
	void		*win;
	void		*mlx;
	t_img_info	img;
	t_img_info	north;
	t_img_info	south;
	t_img_info	west;
	t_img_info	east;

	int			img_width;
	int			img_height;
	// t_img 		*img_ptr;
	// int 		*data_img;

	t_v2f		plane;
	float		time;
	float		old_time;

	// game
	char 		**map;
	int			width;
	int			height;
	t_v2f		player_pos;
	t_v2f		camera_dir;
}	t_data;

int		data_clear(t_data *data);
int		key_event(int keycode, t_data *data);
bool	setup_mlx(t_data *data);

// parsing
bool	is_a_white_space(char c);
int		identify_line(char *str);
bool	setup_world(t_data *data, char *map);
bool	fill_map(t_data *data, char **line, int fd);
void	put_strs(char **strs);
void	put_v2f(t_v2f vecteur);
void	free_strs(char ***strs);
bool	find_player(t_data *data);
bool	checkup_map(char **map);

int		count_char_in_str(char c, char *str);
int		count_char_in_map(char c, char **map);

// fill textures
bool	fill_north(t_data *data, char *line);
bool	fill_south(t_data *data, char *line);
bool	fill_west(t_data *data, char *line);
bool	fill_east(t_data *data, char *line);

// mlx utils
void	ft_my_put_pixel(t_data *data, int x, int y, int color);
void	put_col(t_data *data, int col, int start, int end, int color);

void	render(t_data *data);
float	abs_value(float x);

#endif
