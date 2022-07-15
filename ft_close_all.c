#include "fdf.h"

void	ft_close_all(t_data *data)
{
	printf("chegou no close all\n");
	//free(data->coord);
	ft_lstclear(&data->lines, &free);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}
