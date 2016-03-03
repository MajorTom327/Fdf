/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 06:25:18 by vthomas           #+#    #+#             */
/*   Updated: 2016/03/03 06:43:00 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define W_HEIGHT	1024
# define W_WIDTH	1024

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;
typedef	struct	s_data
{
	void	*mlx;
	void	*win;
}				t_data;
typedef struct	s_poly
{
	int		nb_corner;
	t_coord	*pos_corner;
}				t_poly;
int				f_exit(int keycode, void *data);
int				f_distance(t_coord src, t_coord dst);
t_coord			*f_new_coord(int x, int y);
t_poly			*f_new_poly(int nb_corner);
void			f_draw_line(t_coord src, t_coord dst, t_data data, int c);
void			f_draw_linefade(t_coord src, t_coord dst, t_data data, int *c);
void			f_draw_poly(t_poly poly, int c, t_data data);
void			f_draw_pixelintensity(const t_coord pos, int color, float \
		intensity, const	t_data data);
#endif
