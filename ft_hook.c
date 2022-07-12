#include "fdf.h"

int	render(t_data *data)
{
	t_point	*p0; //APAGAR!
	t_point *p1;
	t_list	*aux;
	int	i;
	int	*s;
	int	j;
	if (data->win_ptr != NULL)
	{
		aux = data->lines;
		//s = aux->content;
		j = -1;
		while (++j < ft_lstsize(data->lines))
		{
			i = 0;
			s = (int *) aux->content;
			while (++i <= s[0])
			{
				printf("s[%d] p0 = %p\n",i, s);
				p0 = ft_iso_coord((i - 1) * 10, j * 10, s[i]);
				//printf("p0->x = %d\n", p0->x);
				//printf("p0->y = %d\n", p0->y);
				if (i < s[0])
				{
					p1 = ft_iso_coord(i * 10, j * 10, s[i + 1]);
					ft_bresenham(p0, p1, data);					
				}
				if (j < ft_lstsize(data->lines) - 1)
				{
				s = (int *) aux->next->content;
				//printf("aux->content = %p\n", aux->content);
				//printf("aux->next->content = %p\n", aux->next->content);
				printf("s[%d] p1 = %p\n",i, s);
				p1 = ft_iso_coord((i - 1) * 10, (j + 1) * 10, s[i]);
				//printf("p1->x = %d\n", p1->x);
				//printf("p1->y = %d\n", p1->y);
				ft_bresenham(p0, p1, data);
			s = (int *) aux->content;
				}
			}
			aux = aux->next;
		}
	//p0.x = 0;
	//p0.y = 0;
	//p1.x = 400;
	//p1.y = 300;
	//ft_bresenham(&p0, &p1, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->image.img_ptr, 0, 0);
	}
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
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, 0, &handle_mouserelease, data);
	mlx_loop(data->mlx_ptr);
}
