#include "fdf.h"

//#define Kx 22
//#define Ky 22


void	ft_draw_right(int u, int v, t_list *node, t_data *data)
{
	t_point	*p0;
	t_point *p1;
	int	*s;
	int	k;
	
	k = data->k;
	s = node->content;
	p0 = ft_iso_coord(u * k, v * k, s[u]);
	p1 = ft_iso_coord((u + 1) * k, v * k, s[u + 1]);
	ft_bresenham(p0, p1, data);
	free(p1);
	free(p0);
}

void	ft_draw_down(int u, int	v, t_list *node, t_data *data)
{
	t_point	*p0;
	t_point *p1;
	int	*s;
	int	k;
	
	k = data->k;
	s = node->content;
	p0 = ft_iso_coord(u * k, v * k, s[u]);
	s = node->next->content;
	p1 = ft_iso_coord(u * k, (v + 1) * k, s[u]);
	ft_bresenham(p0, p1, data);
	free(p1);
	free(p0);
}

void	ft_render_loop(t_data *data)
{
	int	i;
	int	j;
	t_list	*aux;
	int	size;
	int	*s;

	aux = data->lines;
	size = ft_lstsize(aux);
	j = -1;
	while (++j < size)
	{
		i = 0;
		s = aux->content;
		while (++i <= s[0])
		{
			if (i < s[0])
				ft_draw_right(i, j, aux, data);
			if (j < size - 1)
				ft_draw_down(i, j, aux, data);
		}
		aux = aux->next;
	}
}

int	ft_render(t_data *data)
{
	if (!data->win_ptr)
		return (1);
	ft_render_loop(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->image.img_ptr, 0, 0);
	return (0);
}
