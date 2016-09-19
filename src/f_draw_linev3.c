#include "mlx.h"
#include "fdf.h"
#include <math.h>
#include <stdlib.h>

/*
** f_draw_line
** Function take 4 Param:
** 	- 2 param for coord of the extremity of the line
** 	- Data for all needed important info
** 	- Color for the color of the point
*/

void	f_draw_linev3(t_v3 src, t_v3 dst, t_data data, int c)
{
	t_v2	src2;
	t_v2	dst2;
	int	a;
	int		f;

	src2.x = (src.x * data.format.x);
	src2.y = (src.y * data.format.y) - (src.z * data.format.z);
	dst2.x = (dst.x * data.format.x);
	dst2.y = (dst.y * data.format.y) - (dst.z * data.format.z);

//	src2.x = data.pos.x + (src.x * data.format.x);
//	src2.y = data.pos.y + (src.y * data.format.y) - (src.z * data.format.z);
//	dst2.x = data.pos.x + (dst.x * data.format.x);
//	dst2.y = data.pos.y + (dst.y * data.format.y) - (dst.z * data.format.z);

	if (data.angle != 0)
	{
		a = data.angle;
		f = 1;
		src2.x = src2.x * cos(a) - src2.x * sin(a);
		dst2.x = dst2.x * cos(a) - dst2.x * sin(a);
		dst2.y = dst2.y * sin(a) + dst2.y * cos(a);
		src2.y = src2.y * sin(a) + src2.y * cos(a);
		f_draw_line(src2, src2, data, 0x00FF00);
		f_draw_line(dst2, dst2, data, 0x00FF00);
	}
	src2.x += data.pos.x;
	src2.y += data.pos.y;
	dst2.x += data.pos.x;
	dst2.y += data.pos.y;

	f_draw_line(src2, dst2, data, c);
}
