#include <fdf.h>
#include <debug.h>

void	move_grid(t_data *data, t_v3 dir)
{
	t_v2	tmp;

	data->pos.x += dir.x;
	data->pos.y += dir.y;
	refresh(*data);
}

void	resize_grid(t_data *data, t_v3 dir)
{
	if (dir.x)
		data->format.x += dir.x;
	if (dir.y)
		data->format.y += dir.y;
	if (dir.z)
		data->format.z += dir.z;
	refresh(*data);
}
