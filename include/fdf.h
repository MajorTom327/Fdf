/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 06:25:18 by vthomas           #+#    #+#             */
/*   Updated: 2016/03/03 03:05:52 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define W_HEIGHT	640
# define W_WIDTH	640
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
void			f_line(t_coord pos, t_coord target, t_data data, int color);
double			f_getangle(t_coord pos, t_coord target);
int				f_exit(int keycode, void *data);
void			f_pixelintensity(const t_coord pos, int color, float intensity, const	t_data data);
#endif
