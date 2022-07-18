#include "fdf.h"

#define ANG 2.0944
#define A 0.5236

static void	ft_rotate(int *x, int *y, t_data *data)
{
	float	a;
	int	xr;
	int	yr;

	a = data->angle;
	xr = *x * cos(a) - *y * sin(a);
	yr = *y * cos(a) + *x * sin(a);
	*x = xr;
	*y = yr;
}

t_point	*ft_iso_coord(int x, int y, int z, t_data *data)
{
	t_point	*point;
	int	delta_x;
	int	delta_y;

	point = (t_point *) malloc(sizeof(t_point));
	delta_x = data->delta_x;
	delta_y = data->delta_y;
	ft_rotate(&x, &y, data);
	if (!data->perspective)
	{
		point->x = round(x * cos(A) + y * cos(A + ANG) + \
		z * cos(A - ANG)) + (IMG_WIDTH / 2) + delta_x;
		point->y = round(x * sin(A) + y * sin(A + ANG) + \
		z * sin(A - ANG)) + (IMG_HEIGHT / 2) + delta_y;
	}
	else
	{
		point->x = round(x + z * cos(A)) + (IMG_WIDTH / 2) + delta_x;
		point->y = round(y + z * sin(A)) + (IMG_HEIGHT / 2) + delta_y;
	}
	point->z_orig = z;
	return (point);
}
