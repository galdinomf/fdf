#include "fdf.h"

#define ANG 2.0944
#define A 0.5236
//A 0.5236
//sqrt(3)/2 = 0.866

t_point	*ft_iso_coord(int x, int y, int z)
{
	t_point	*point;
	
	point = (t_point *) malloc(sizeof(t_point));
	//printf("x = %d, y = %d, z = %d\n", x, y, z);
	point->x = round(x * cos(A) + y * cos(A + ANG) + z * cos(A - ANG)) + (IMG_WIDTH / 4);
	point->y = round(x * sin(A) + y * sin(A + ANG) + z * sin(A - ANG)) + (IMG_HEIGHT / 8);
	point->z_orig = z;
	//point->x = x;
	//point->y = y;
	//point->x = 0.866 * x - 0.866 * y;
	//point->y = 0.5 * x + 0.5 *y + z;
	return (point);
}
