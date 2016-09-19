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

	src2.x = src.x;
	src2.y = src.y - (src.z * FDF_BASE_LVL);
	dst2.x = dst.x;
	dst2.y = dst.y - (dst.z * FDF_BASE_LVL);
	f_draw_line(src2, dst2, data, c);
}
