#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	ft_initialize(&data);
	if (argc == 2)
	{
		ft_read_map(argv[1], &data);
	}

	ft_get_k(&data);
	ft_hook(&data);
	ft_close_all(&data);
	return (0);
}
