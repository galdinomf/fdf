#include "fdf.h"

void	ft_argc_errors(int argc)
{
	if (argc == 1)
		write(1, "File name missing.\n", 19);
	if (argc > 2)
		write(1, "Too many arguments!\n", 20);
}
