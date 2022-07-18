#include "fdf.h"

void	ft_close_window(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image.img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
}
