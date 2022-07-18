#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
	{
		ft_argc_errors(argc);
		return (1);
	}
	if (ft_read_map(argv[1], &data))
		return (1);
	ft_initialize(&data);
	ft_get_k(&data);
	ft_hook(&data);
	ft_close_all(&data);
	return (0);
}
