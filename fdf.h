#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
#include <stdio.h>

# define MLX_ERROR 1
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

# define IMG_WIDTH 800
# define IMG_HEIGHT 600

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_list
{
	void	*content;
	struct s_list	*next;
}	t_list;

typedef struct s_img
{
	void	*img_ptr;
	int	*data;
	int	size_l;
	int	bpp;
	int	endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_list	*lines;
	t_img	image;
}	t_data;

typedef struct s_point
{
	int	x;
	int	y;
	int	z_orig;
}	t_point;

int	ft_initialize(t_data *data);
void	ft_close_all(t_data *data);
void	ft_hook(t_data *data);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
int	ft_lstsize(t_list *lst);
char	*get_next_line(int fd);
int	ft_char_in_buffer(char c, char *buf);
char	*ft_accumulate_buffer(char *acc, char *buf, int bytes_read);
char	*ft_extract_remainder_bytes_from_line(char *acc);
int	ft_initialize_and_get_line(int fd, char *buf, char **acc);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_read_map(char *path, t_data *data);
char	**ft_split(char const *s, char c);
void	ft_bresenham(t_point *p0, t_point *p1, t_data *data);
int	ft_atoi(const char *nptr);
t_point	*ft_iso_coord(int x, int y, int z);

#endif
