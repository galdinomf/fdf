#include "fdf.h"

int	*ft_get_values(char **s)
{
	int	i;
	int	*values;
	int	count;

	i = 0;
	while (s[i])
		i++;
	values = (int *) malloc((i + 1) * sizeof(int));
	values[0] = i;
	count = 0;
	while (count < i)
	{
		values[count + 1] = ft_atoi(s[count]);
		count++;
	}
	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
	return (values);
}

int	ft_read_map(char *path, t_data *data)
{
	char	*s;
	t_list	*aux_node;
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 3)
	{
		write(1, "File opening failed.\n", 21);
		return (1);
	}
	s = get_next_line(fd);
	data->lines = ft_lstnew(ft_get_values(ft_split(s, ' ')));
	free(s);
	while (s)
	{
		s = get_next_line(fd);
		if (s)
		{
			aux_node = ft_lstnew(ft_get_values(ft_split(s, ' ')));
			ft_lstadd_back(&data->lines, aux_node);
		}
		free(s);
	}
	return (0);
}
