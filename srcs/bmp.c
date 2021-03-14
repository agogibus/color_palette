
#include "bmp.h"

t_bmp_dib	dib(int w, int h)
{
	t_bmp_dib	header;

	bzero(&header, sizeof(t_bmp_dib));
	header.self_size = sizeof(t_bmp_dib);
	header.height = h;
	header.width = w;
	header.hz_res = 2835;
	header.vt_res = 2835;
	header.color.bpp = 32;
	header.color.color_planes = 1;
	header.important_count = 16;
	return (header);
}

t_bmp_head	head(int w, int h)
{
	t_bmp_head	header;

	bzero(&header, sizeof(t_bmp_head));
	header.magic = 0x4D42;
	header.offset = sizeof(t_bmp_head) + sizeof(t_bmp_dib);
	header.size = header.offset + w * h * 4;
	return (header);
}


