/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 20:18:25 by vthomas           #+#    #+#             */
/*   Updated: 2016/09/21 21:30:12 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <mlx.h>
#include <get_next_line.h>
#include <libft.h>

#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

void	refresh(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	draw_grid(data, data->grid, data->size, 0xFFFFFF);
}

void	print_file(t_data *data)
{
	int		fd;
	int		count;
	char	*str;

	if ((fd = open(data->file, O_RDONLY)) < 2)
		return ;
	count = 0;
	ft_putstr("\n\033[34m[");
	ft_putnbr(data->size.x);
	ft_putchar(':');
	ft_putnbr(data->size.y);
	ft_putendl("]\033[0m");
	while (get_next_line(fd, &str))
	{
		ft_putstr("\033[32;4m");
		ft_putnbr(count++);
		ft_putstr(":\033[0m\t");
		ft_putendl(str);
	}
	close(fd);
	ft_strdel(&str);
}

void	print_grid(t_data *data)
{
	t_v2	p;

	p.y = -1;
	ft_putstr("\n\033[34m[");
	ft_putnbr(data->size.x);
	ft_putchar(';');
	ft_putnbr(data->size.y);
	ft_putendl("]\033[0m");
	ft_putstr("\t");
	while (p.y++ < data->size.x - 1)
	{
		ft_putstr("\033[32;4m");
		ft_putnbr(p.y);
		ft_putstr(":\t\033[0m");
	}
	ft_putchar('\n');
	p.y = -1;
	while (p.y++ < data->size.y - 1)
	{
		p.x = 0;
		ft_putstr("\033[32;4m");
		ft_putnbr(p.y);
		ft_putstr(":\t\033[0m");
		while (p.x < data->size.x - 1)
		{
			ft_putnbr(data->grid[p.y][p.x].z);
			ft_putchar('\t');
			p.x++;
		}
		ft_putchar('\n');
	}
}
