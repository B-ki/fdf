/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:46:28 by rmorel            #+#    #+#             */
/*   Updated: 2022/05/11 17:11:31 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include	<stdlib.h>
# include	<time.h>
# include	"libft.h"
# include	<mlx.h>
# include	<X11/X.h>
# include	<fcntl.h>
# include	<unistd.h>
# include	<math.h>
# include	<stdio.h>

# define W_W 1920
# define W_H 1080

# define RIGHT 65363
# define DOWN 65364
# define LEFT 65361
# define UP 653632
# define ESC 65307
# define COST 0.9848
# define COSMT 0.9848
# define SINT 0.1736
# define SINMT 0.1736
# define SCALE 20
# define SCALE_BIG 5
# define RGB_POS_MIN 0xF5F5DC
# define RGB_POS_MAX 0x8B4513
# define RGB_NEG_MAX 0x000033
# define RGB_NEG_MIN 0xCAE1FF
# define RGB_NULL 0xFFD700

typedef struct s_var {
	float	i;
	float	j;
	int		m;
}		t_var;

typedef struct s_point {
	float			x;
	float			y;
	float			z;
	u_int32_t		trgb;
}		t_point;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_lgth;
	int		endian;
	int		x;
	int		y;
}				t_data;

typedef struct s_fdf {
	t_point	*map;
	t_point	*m_cpy;
	t_data	*data;
	void	*mlx;
	void	*win;
	int		trgb;
	int		key_time;
}				t_fdf;

//	colors.c

int			create_trgb(int t, int r, int g, int b);
int			get_t(int trgb);
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);

//	colors2.c

int			add_shade(double distance, int color);
int			get_opposite_color(int trgb);
int			average_color(int trgb_1, int trgb_2);
int			color_grad(float x, int z);
void		fill_color(t_fdf *fdf);

//	colors3.c

float		get_max_z(t_fdf *fdf);
float		get_min_z(t_fdf *fdf);

//	draw.c

void		draw_map(t_fdf *fdf);
void		init_map(t_point *map);
void		translate_map_x(t_point *map, float t);
void		translate_map_y(t_point *map, float t);

//	gnl.c

char		*get_next_line(int fd);
char		*join_gnl(char *prev, char *buff);
int			size_gnl(char *s, int start, int len);
char		*substr_gnl(char *s, int start, int len);
char		*newline_gnl(char **prev);

//	gnl2.c

char		*search_nl(char *s);

//	helper.c

void		try_all_lines(t_fdf *fdf);
void		check_variables(t_fdf *fdf);
void		check_points(t_fdf *fdf);
t_point		*point(int x, int y, int z);

//	hook.c

int			enter_window(int x, int y, t_fdf *fdf);
int			key_hook(int keycode, t_fdf *fdf);
int			key_down_moves(int keycode, t_fdf *fdf);
int			red_cross(t_fdf *fdf);

//  image.c

void		clear_image(t_fdf *fdf);
void		my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
int			render_next_frame(t_fdf *fdf);
int			in_window(t_point *t_p1, t_point *t_p2);

//	line.c

void		bres(t_point *t_p1, t_point *t_p2, t_fdf *fdf);
void		bres_0_1(t_point *t_p1, t_point *t_p2, t_fdf *fdf, int trgb);
void		bres_1_8(t_point *t_p1, t_point *t_p2, t_fdf *fdf, int trgb);
void		bres_0_m1(t_point *t_p1, t_point *t_p2, t_fdf *fdf, int trgb);
void		bres_m1_m8(t_point *t_p1, t_point *t_p2, t_fdf *fdf, int trgb);

//	main.c

void		init_window(t_fdf *fdf);
void		exit_clean(t_fdf *fdf);

//  parsing.c

float		count_line(char *str);
float		count_col(char *str);
t_point		*str_to_map(char *line, char **total_line);
void		fill_map(t_point *map, t_var v, char **line_split);
void		create_copy(t_fdf *fdf);

//	parsing2.c

t_point		*create_map(char **av, t_fdf *fdf);
void		fill_zero_map(t_point *map, char *line);
void		free_split(char **tab);
u_int32_t	hex_to_int(char *hex);
void		copy_map(t_point *m1, t_point *m2);

//  rotation.c

void		rotation_x(t_fdf *fdf, float angle);
void		rotation_y(t_fdf *fdf, float angle);
void		rotation_z(t_fdf *fdf, float angle);

//	zoom.c

void		zoom_in(t_fdf *fdf);
void		zoom_out(t_fdf *fdf);

#endif
