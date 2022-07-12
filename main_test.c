#include <stdlib.h>
#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdio.h>
#include <math.h>

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define MLX_ERROR 1

# define IMG_WIDTH 400
# define IMG_HEIGHT 300

typedef struct s_img
{
	void	*img_ptr;
	int	*data;
	//no need to undertand values below
	int	size_l;
	int	bpp;
	int	endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_data;


int	handle_mouserelease(t_data *data)
{
	if (1)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	//printf("Keyrelease: %d\n", button);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	printf("Keypress: %d\n", keysym);
	return(0);
}

int	handle_no_event(void *data)
{
	return (0);
}

int	main(void)
{
	t_data	data;
	int	t;
	int	n;
	float	x;
	float	y;
	float 	aux;
	int	aux2;
	//initializing
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	//creating window
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
	if (data.win_ptr == NULL)
		return (MLX_ERROR);
	//creating image
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	data.img.data = (int *)mlx_get_data_addr(data.img.img_ptr, &data.img.bpp, &data.img.size_l, &data.img.endian);
	data.img.data[IMG_WIDTH*150 + 200] = -1;	
	n = 600;
	t = -1;
	while (++t < n)
	{
		aux2 = round(200 + 100*cos(t*2*M_PI/n)) + IMG_WIDTH*round(150 - 100*sin(t*2*M_PI/n));
		//aux2 = round(aux);
		data.img.data[aux2] = -1;
	}
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.img_ptr, 100, 100);
/*	n = 1000;
	t = -1;
	while (++t < n)
	mlx_pixel_put(data.mlx_ptr, data.win_ptr, 400 + 100*cos(t*2*M_PI/n), 300 - 100*sin(t*2*M_PI/n), 0xFFFFFF00);
	t = -1;
	while (++t < 700)
	mlx_pixel_put(data.mlx_ptr, data.win_ptr, 50 + t, 100, 0xFFFFFF00);
	t = -1;
	while (++t < 100)
	mlx_pixel_put(data.mlx_ptr, data.win_ptr, 50 + t, 350 - 0.5*t, 0xFFFFFF00);
*/	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	//mlx_key_hook(data.win_ptr, &handle_keyrelease, &data);
	mlx_mouse_hook (data.win_ptr, &handle_keypress, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, 0, &handle_mouserelease, &data);
	//mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}

/*
int	mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int	mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int	mlx_expose_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int	mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);
int	mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);
*/
