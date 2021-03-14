
#ifndef __BMP_H
# define __BMP_H

#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <fcntl.h>

typedef struct				s_color_def_data
{
	unsigned short	color_planes;
	unsigned short	bpp;
}							t_color_def_data;

typedef union				u_color_def
{
	int					unused;
	t_color_def_data	data;
}							t_color_def;

# pragma pack(push, 1)

typedef struct				s_bmp_head
{
	unsigned short	magic;
	unsigned int	size;
	unsigned short	unused_1;
	unsigned short	unused_2;
	unsigned int	offset;
}							t_bmp_head;

# pragma pack(pop)

typedef struct				s_bmp_dib
{
	unsigned int		self_size;
	int					width;
	int					height;
	t_color_def_data	color;
	int					compression;
	int					img_size;
	unsigned int		hz_res;
	unsigned int		vt_res;
	unsigned int		color_count;
	unsigned int		important_count;
}							t_bmp_dib;


t_bmp_dib	dib(int w, int h);
t_bmp_head	head(int w, int h);

#endif
