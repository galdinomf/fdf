#include "fdf.h"

int	ft_initialize(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, \
	WINDOW_HEIGHT, "FDF");
	if (data->win_ptr == NULL)
		return (MLX_ERROR);
	data->image.img_ptr = mlx_new_image(data->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	data->image.data = (int *)mlx_get_data_addr(data->image.img_ptr, \
	&data->image.bpp, &data->image.size_l, &data->image.endian);
	data->delta_x = 0;
	data->delta_y = 0;
	data->angle = 0;
	data->perspective = 0;
	return (0);
}
