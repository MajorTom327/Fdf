#include <fdf.h>
#include <mlx.h>
#include <debug.h>

void	refresh(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	draw_grid(data, data->grid, data->size, 0xFFFFFF);
}
