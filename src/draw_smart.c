#include "../include/cub3d.h"

void	draw_smart(t_data *data, t_img_info *img, int x, int y)
{
	static int	info = {0, 3,  ALICE_2, ALICE_3, ALICE_4, WHITE_RABBIT_1, WHITE_RABBIT_2, WHITE_RABBIT_3,};
	int			width;

	width = ft_strlen(img->addr) / ( * info[data->dialog_stage]);

}
