#include "fdf.h"

#define ANG 2.0944
//#define A 0.5236
//A 0.5236
//sqrt(3)/2 = 0.866

t_point	*ft_iso_coord(int x, int y, int z, t_data *data)
{
	t_point	*point;
	float	a;
	
	point = (t_point *) malloc(sizeof(t_point));
	//printf("x = %d, y = %d, z = %d\n", x, y, z);
	a = data->angle;
	point->x = round(x * cos(a) + y * cos(a + ANG) + 10 * z * cos(a - ANG)) + (IMG_WIDTH / 3);
	point->y = round(x * sin(a) + y * sin(a + ANG) + 10 * z * sin(a - ANG)) + (IMG_HEIGHT / 3);
	point->z_orig = z;
	//point->x = x;
	//point->y = y;
	//point->x = 0.866 * x - 0.866 * y;
	//point->y = 0.5 * x + 0.5 *y + z;
	return (point);
}
