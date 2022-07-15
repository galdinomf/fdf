#include "fdf.h"

void	ft_define_direction(int *ti, int *dt)
{
	if (*dt < 0)
	{
		*ti = -1;
		*dt *= -1;
	}
}

int	ft_in_limits(int x, int y)
{
	if ((x >= 0) && (x < IMG_WIDTH))
	{
		if ((y >= 0) && (y < IMG_HEIGHT))
			return (1);
	}
	return (0);
}

void	ft_plot_line_low(t_point *p0, t_point *p1, t_data *data)
{
	int	dx;
	int	dy;
	int	D;
	int	y;
	int	yi;

	dx = p1->x - p0->x;
	dy = p1->y - p0->y;
	yi = 1;
	ft_define_direction(&yi, &dy);
	D = (2 * dy) - dx;
	y = p0->y;
	while (p0->x <= p1->x)
	{
		if (ft_in_limits(p0->x, y))
			data->image.data[IMG_WIDTH * y + p0->x] = -1;
		if (D > 0)
		{
			y += yi;
			D += 2 * (dy - dx);
		}
		else
			D += 2 * dy;
		++p0->x;
	}
}

void	ft_plot_line_high(t_point *p0, t_point *p1, t_data *data)
{
	int	dx;
	int	dy;
	int	D;
	int	x;
	int	xi;

	dy = p1->y - p0->y;
	dx = p1->x - p0->x;
	xi = 1;
	ft_define_direction(&xi, &dx);
	D = (2 * dx) - dy;
	x = p0->x;
	while (p0->y <= p1->y)
	{
		if (ft_in_limits(x, p0->y))
			data->image.data[IMG_WIDTH * p0->y + x] = -1;
		if (D > 0)
		{
			x += xi;
			D += 2 * (dx - dy);
		}
		else
			D += 2 * dx;
		++p0->y;
	}
}

void	ft_bresenham(t_point *p0, t_point *p1, t_data *data)
{
	if (abs(p1->y - p0->y) < abs(p1->x - p0->x))
	{
		if (p0->x > p1->x)
			ft_plot_line_low(p1, p0, data);
		else
			ft_plot_line_low(p0, p1, data);
	}
	else
	{
		if (p0->y > p1->y)
			ft_plot_line_high(p1, p0, data);
		else
			ft_plot_line_high(p0, p1, data);
	}
}
