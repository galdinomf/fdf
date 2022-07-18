#include "fdf.h"

void	ft_turn(int keysym, t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image.img_ptr);
	if (keysym == 103)
		data->angle += 0.03;
	if (keysym == 104)
		data->angle -= 0.03;
	data->image.img_ptr = mlx_new_image(data->mlx_ptr, \
	IMG_WIDTH, IMG_HEIGHT);
}

void	ft_contract(int keysym, t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image.img_ptr);
	if (keysym == 120)
		data->k += 1;
	if (keysym == 122)
		data->k -= 1;
	if (data->k < 0)
		data->k = 0;
	data->image.img_ptr = mlx_new_image(data->mlx_ptr, \
	IMG_WIDTH, IMG_HEIGHT);
}

void	ft_translate_vertical(int keysym, t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image.img_ptr);
	if (keysym == 119)
		data->delta_y -= 10;
	if (keysym == 115)
		data->delta_y += 10;
	data->image.img_ptr = mlx_new_image(data->mlx_ptr, \
	IMG_WIDTH, IMG_HEIGHT);
}

void	ft_translate_horizontal(int keysym, t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image.img_ptr);
	if (keysym == 97)
		data->delta_x -= 10;
	if (keysym == 100)
		data->delta_x += 10;
	data->image.img_ptr = mlx_new_image(data->mlx_ptr, \
	IMG_WIDTH, IMG_HEIGHT);
}

int	ft_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		ft_close_window(data);
	if ((keysym == 103) || (keysym == 104))
		ft_turn(keysym, data);
	if ((keysym == 122) || (keysym == 120))
		ft_contract(keysym, data);
	if (keysym == 99)
	{
		mlx_destroy_image(data->mlx_ptr, data->image.img_ptr);
		data->perspective = !data->perspective;
		data->image.img_ptr = mlx_new_image(data->mlx_ptr, \
		IMG_WIDTH, IMG_HEIGHT);
	}
	if ((keysym == 119) || (keysym == 115))
		ft_translate_vertical(keysym, data);
	if ((keysym == 97) || (keysym == 100))
		ft_translate_horizontal(keysym, data);
	if (keysym == 110)
		ft_modify_z(1, data);
	if (keysym == 109)
		ft_modify_z(-1, data);
	return (0);
}
