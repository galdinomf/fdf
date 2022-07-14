#include "fdf.h"

void	ft_get_k(t_data *data)
{
	int	kx;
	int	ky;
	int	*s;
	t_list	*aux;
	int	*i;
	
	aux = data->lines;
	s = aux->content;
	while (aux->next)
	{
		i = aux->next->content;
		if (i[0] > s[0])
			s = i;
		aux = aux->next;		
	}
	kx = IMG_WIDTH / (2 * s[0]);
	ky = IMG_HEIGHT / (2 * ft_lstsize(data->lines));
	if (kx < ky)
		data->k = kx;
	else
		data->k = ky;
}
