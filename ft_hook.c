#include "fdf.h"

int	handle_mouserelease(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image.img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	return (0);
}

void	ft_hook(t_data *data)
{
	//tentar tirar o loop hook. trocar pelo expose hook
	//mlx_loop_hook(data->mlx_ptr, &handle_no_event, data);
	mlx_loop_hook(data->mlx_ptr, &ft_render, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &ft_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, 0, &handle_mouserelease, data);
	mlx_loop(data->mlx_ptr);
}
