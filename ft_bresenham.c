
//this code only works with lines drawn from left to right and top-down
#include "fdf.h"

void	ft_plot_low(int dx, int dy, t_point *p0, t_data *data)
{
	int	x1;
	int	x;
	int	y;
	int	D;
	int	yi;
	
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy *= -1;
	}
	y = p0->y;
	x = p0->x - 1;
	x1 = dx + p0->x;
	D = (2 * dy) - dx;
	while (++x <= x1)
	{
		//printf("low x = %d, y = %d\n", x, y);
		if (p0->z_orig == 10)
			data->image.data[IMG_WIDTH*y + x] = 65280;
		else			
			data->image.data[IMG_WIDTH*y + x] = -1;
		//data->image.data[data->image.size_l*y + (data->image.bpp / 8)*x] = -1;
		if (D > 0)
		{
			y += yi;
			D -= 2 * dx;
		}
			D += 2 * dy;
	}
}

void	ft_plot_high(int dx, int dy, t_point *p0, t_data *data)
{
	int	y1;
	int	x;
	int	y;
	int	D;
	int	xi;
	
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx *= -1;
	}
	y = p0->y - 1;
	x = p0->x;
	y1 = dy + p0->y;
	D = (2 * dx) - dy;
	while (++y <= y1)
	{
		//printf("high x = %d, y = %d, data = %p\n", x, y, data);
//		if ((x >=0) && (y >= 0))
		if (p0->z_orig == 10)
			data->image.data[IMG_WIDTH*y + x] = 65280;
		else			
			data->image.data[IMG_WIDTH*y + x] = -1;
		//data->image.data[data->image.size_l*y + (data->image.bpp / 8)*x] = -1;
		if (D > 0)
		{
			x += xi;
			D -= 2 * dy;
		}
			D += 2 * dx;
	}
}

void	ft_bresenham(t_point *p0, t_point *p1, t_data *data)
{
	int	dx;
	int	dy;
	
	dx = p1->x - p0->x;
	dy = p1->y - p0->y;
	if (dy < dx)
	{
		ft_plot_low(dx, dy, p0, data);
	}
	else
	{
		ft_plot_high(dx, dy, p0, data);
	}
}


