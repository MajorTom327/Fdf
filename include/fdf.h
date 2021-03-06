/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 06:25:18 by vthomas           #+#    #+#             */
/*   Updated: 2016/09/24 23:33:02 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define W_TITLE 	"fdf"
# define W_HEIGHT	1024
# define W_WIDTH	1024
# define FDF_BASE_X			16
# define FDF_BASE_Y			8
# define FDF_BASE_LVL		4
# define FDF_MOVE_PADDING 	8
# define FDF_MARGIN	W_HEIGHT / 5

# define VK_LEFT	123
# define VK_UP		126
# define VK_RIGHT	124
# define VK_DOWN	125
# define VK_ADD		69
# define VK_SUB		78
# define VK_W		13
# define VK_A		0
# define VK_S		1
# define VK_D		2
# define VK_1		18
# define VK_2		19
# define VK_NUM_0	82
# define VK_NUM_1	83
# define VK_NUM_2	84
# define VK_NUM_3	85

# include <vector.h>

typedef	struct	s_data
{
	void	*mlx;
	void	*win;
	t_v3	**grid;
	t_v2	size;
	t_v3	format;
	t_v2	pos;
	int		current_y;
	char	*file;
	float	angle;
	int		show;
}				t_data;

int				f_distance(t_v2 src, t_v2 dst);
void			f_draw_line(t_v2 src, t_v2 dst, t_data data, int c);
void			f_draw_linev3(t_v3 src, t_v3 dst, t_data data, int c);

int				f_mouse(int btn, int x, int y, void *param);
int				f_exit(int keycode, void *data);
int				f_exitfull(void *data);
int				event_key(int keycode, t_data *data);

void			get_grid(const char *av, t_v2 *size, t_data *data);
int				cleargnl(int fd);

void			draw_grid(t_data *data, t_v3 **grid, t_v2 size, int c);
void			print_grid(t_data *data);
void			print_file(t_data *data);
void			refresh(t_data *data);

void			move_grid(t_data *data, int keycode);
void			resize_grid(t_data *data, int keycode);

void			usage(void);
void			exitf(void);
void			exitfile(void);
void			exitm(void *mem);
#endif
