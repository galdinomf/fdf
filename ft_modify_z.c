#include "fdf.h"

void	ft_increase_z(void *content)
{
	int	*s;
	int	i;

	s = (int *) content;
	i = 0;
	while (++i <= s[0])
	{
		if (s[i] > 0)
			++s[i];
	}
}

void	ft_decrease_z(void *content)
{
	int	*s;
	int	i;

	s = (int *) content;
	i = 0;
	while (++i <= s[0])
	{
		if (s[i] > 0)
			--s[i];
	}
}

void	ft_modify_z(int n, t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image.img_ptr);
	data->delta_z += n * 1;
	data->image.img_ptr = mlx_new_image(data->mlx_ptr, \
	IMG_WIDTH, IMG_HEIGHT);
}
