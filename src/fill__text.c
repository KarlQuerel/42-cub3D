#include "../include/cub3d.h"

bool	get_text(t_data *data)
{
	if (!upload_img(data, &((data->dialog)[0]), ALICE_D_1A))
		return (err(strerror(errno)), false);
	if (!upload_img(data, &((data->dialog)[1]), ALICE_D_1B))
		return (err(strerror(errno)), false);
	if (!upload_img(data, &((data->dialog)[3]), ALICE_D_2A))
		return (err(strerror(errno)), false);
	if (!upload_img(data, &((data->dialog)[4]), ALICE_D_2B))
		return (err(strerror(errno)), false);
	if (!upload_img(data, &((data->dialog)[7]), ALICE_D_3))
		return (err(strerror(errno)), false);
	if (!upload_img(data, &((data->dialog)[10]), ALICE_D_4))
		return (err(strerror(errno)), false);
	if (!upload_img(data, &((data->dialog)[2]), RABBIT_D_1))
		return (err(strerror(errno)), false);
	if (!upload_img(data, &((data->dialog)[5]), RABBIT_D_2A))
		return (err(strerror(errno)), false);
	if (!upload_img(data, &((data->dialog)[6]), RABBIT_D_2B))
		return (err(strerror(errno)), false);
	if (!upload_img(data, &((data->dialog)[8]), RABBIT_D_3A))
		return (err(strerror(errno)), false);
	if (!upload_img(data, &((data->dialog)[9]), RABBIT_D_3B))
		return (err(strerror(errno)), false);
	return (true);
}
