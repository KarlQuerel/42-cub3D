/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:01:40 by pcheron           #+#    #+#             */
/*   Updated: 2024/02/09 12:27:58 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "cub3d.h"

void	draw_catterpilar(t_data *data, int x, int end, int i);
void	draw_dialog_box(t_data *data, int x, int y);
void	draw_msg(t_data *data, int x, int y);

void	my_put_img_to_img_reverse(t_data *data, t_img_info *src, int x, int y);
void	my_put_img_to_img(t_data *data, t_img_info *src, int x, int y);

void	open_doors(t_data *data);
void	close_doors(t_data *data);
void	take_collectibles(t_data *data);

bool	upload_img(t_data *data, t_img_info *img, char *file);
bool	get_all_dialog(t_data *data);
bool	get_alice(t_data *data);
bool	get_dialog_box(t_data *data);
bool	get_door(t_data *data);
bool	get_catterpilar(t_data *data);
bool	get_white_rabbit(t_data *data);
bool	get_wall_cat(t_data *data);
bool	get_dialog_cat(t_data *data);
bool	get_characters(t_data *data);
bool	get_mushroom(t_data *data);

void	last_cube(t_data *data, t_v2f ray, int i, t_v2f delta_dist);
void	draw_someone(t_data *data, int col);

void	draw_all(t_data *data);
void	draw_minimap(t_data *data, int x, int y);
void	draw_alice(t_data *data, int x, int y);
void	draw_white_rabbit(t_data *data, int x, int y);
void	draw_cheshire_cat(t_data *data, int x, int y);

// time
void	update_time(t_data *data);
bool	setup_bonus(t_data *data);

float	abs_value(float x);
void	side_calc(t_data *data, t_v2f ray, t_v2f delta_dist);

void	draw_collectible(t_data *data, int x, int end, int i);

#endif
