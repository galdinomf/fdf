#include "fdf.h"

int	render(t_data *data)
{
	t_point	*p0; //APAGAR!
	t_point *p1;
	
	p0 = (t_point *) malloc(sizeof(t_point));
	p1 = (t_point *) malloc(sizeof(t_point));
	p0->x = 0;
	p0->y = 0;
	p1->x = 400;
	p1->y = 300;
	ft_bresenham(p0, p1, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->image.img_ptr, 0, 0);
	free(p0);
	free(p1);
	return (0);
}

int	handle_no_event()
{
	return (0);
}

int	handle_mouserelease(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image.img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(data->mlx_ptr, data->image.img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

void	ft_hook(t_data *data)
{
	//tentar tirar o loop hook. trocar pelo expose hook
	//mlx_loop_hook(data->mlx_ptr, &handle_no_event, data);
	mlx_loop_hook(data->mlx_ptr, &ft_render, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, 0, &handle_mouserelease, data);
	mlx_loop(data->mlx_ptr);
}
