#include <fdf.h>
#include <libft.h>
#include <unistd.h>
#include <debug.h>

void	draw_grid(t_data *data, t_v3 **grid, t_v2 size, int c)
{
	t_v2	p;

	p.y = 0;
	while (p.y < size.y)
	{
		p.x = 0;
		while (p.x < size.x - 1)
		{
			data->current_y = p.y;
			if (p.x > 0)
				f_draw_linev3(grid[p.y][p.x], grid[p.y][p.x - 1], *data, c);
			if (p.y > 0)
				f_draw_linev3(grid[p.y][p.x], grid[p.y - 1][p.x], *data, c);
			if (p.x + 1 < size.x - 1)
				f_draw_linev3(grid[p.y][p.x], grid[p.y][p.x + 1], *data, c);
			if (p.y + 1 < size.y)
				f_draw_linev3(grid[p.y][p.x], grid[p.y + 1][p.x], *data, c);
			p.x++;
		}
		p.y++;
	}
}
