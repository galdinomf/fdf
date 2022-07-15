#include "fdf.h"

void	ft_turn(int signal, t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image.img_ptr);
	data->angle += signal * 0.03;
	data->image.img_ptr = mlx_new_image(data->mlx_ptr, \
	IMG_WIDTH, IMG_HEIGHT);
}

void	ft_contract(int signal, t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image.img_ptr);
	data->k += signal * 1;
	data->image.img_ptr = mlx_new_image(data->mlx_ptr, \
	IMG_WIDTH, IMG_HEIGHT);
}

void	ft_translate_vertical(int signal, t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image.img_ptr);
	data->delta_y += signal * 3;
	data->image.img_ptr = mlx_new_image(data->mlx_ptr, \
	IMG_WIDTH, IMG_HEIGHT);
}

void	ft_translate_horizontal(int signal, t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image.img_ptr);
	data->delta_x += signal * 3;
	data->image.img_ptr = mlx_new_image(data->mlx_ptr, \
	IMG_WIDTH, IMG_HEIGHT);
}

int	ft_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(data->mlx_ptr, data->image.img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}	
	if (keysym == 103)
		ft_turn(1, data);
	if (keysym == 104)
		ft_turn(-1, data);
	if (keysym == 122)
		ft_contract(1, data);
	if (keysym == 120)
		ft_contract(-1, data);
	if (keysym == 119)
		ft_translate_vertical(-1, data);
	if (keysym == 115)
		ft_translate_vertical(1, data);;
	if (keysym == 97)
		ft_translate_horizontal(-1, data);;
	if (keysym == 100)
		ft_translate_horizontal(1, data);
	printf("keysym = %d\n", keysym);
	return (0);
}
