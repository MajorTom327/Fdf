#include <fdf.h>
#include <libft.h>
#include <unistd.h>
#include <debug.h>

static void print_grid(t_v3 **grid, t_v2 size)
{
	t_v2	pos;

	pos.y = 0;
	while (pos.y < size.y)
	{
		pos.x = 0;
		while (pos.x < size.x - 1)
		{
			ft_putchar('[');
			if (grid[pos.y][pos.x].x != 0 || grid[pos.y][pos.x].y != 0 || grid[pos.y][pos.x].x != 0)
				ft_putstr("\033[32m");
			if (grid[pos.y][pos.x].x < 10)
				ft_putchar('0');
			ft_putnbr(grid[pos.y][pos.x].x);
			ft_putchar(':');
			if (grid[pos.y][pos.x].y < 10)
				ft_putchar('0');
			ft_putnbr(grid[pos.y][pos.x].y);
			ft_putchar(':');
			if (grid[pos.y][pos.x].z < 10)
				ft_putchar('0');
			ft_putnbr(grid[pos.y][pos.x].z);
			if (grid[pos.y][pos.x].x != 0 || grid[pos.y][pos.x].y != 0 || grid[pos.y][pos.x].x != 0)
				ft_putstr("\033[0m");
			ft_putstr("] ");
			pos.x++;
		}
		pos.y++;
		ft_putendl("");
	}
}

void draw_grid(t_data data, t_v3 **grid, t_v2 size, int c)
{
	t_v2	pos;

	dbg_info("draw_grid", "Start drawing...", 1);
	dbg_diff_int("draw_grid", "size", size.x, 0, 1);
	dbg_diff_int("draw_grid", "size", size.y, 1, 1);
	print_grid(grid, size);
	pos.y = 0;
	while (pos.y < size.y)
	{
		pos.x = 0;
		while (pos.x < size.x - 1)
		{
			//mlx_pixel_put(data.mlx, data.win, grid[pos.y][pos.x].y, grid[pos.y][pos.x].x, 0x00FF00);
			if (pos.x > 0)
				f_draw_linev3(grid[pos.y][pos.x], grid[pos.y][pos.x - 1], data, c);
			if (pos.y > 0)
				f_draw_linev3(grid[pos.y][pos.x], grid[pos.y - 1][pos.x], data, c);
			if (pos.x + 1 < size.x - 1)
				f_draw_linev3(grid[pos.y][pos.x], grid[pos.y][pos.x + 1], data, c);
			if (pos.y + 1 < size.y)
				f_draw_linev3(grid[pos.y][pos.x], grid[pos.y + 1][pos.x], data, c);
			pos.x++;
		}
		pos.y++;
	}
	dbg_info("draw_grid", "Done !", 1);
}
