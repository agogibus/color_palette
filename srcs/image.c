
#include "image.h"

t_env	*env(void)
{
	static t_env	env;
	static int		init = 0;

	if (!init)
	{
		init = 1;
		env.w = COLOR_COUNT_ROW * COLOR_SIZE;
		env.h = COLOR_COUNT_ROW * COLOR_SIZE;
	}
	return (&env);
}

void set_img(unsigned int *buf, int w, int h) {
	for (int i = 0; i < w * h; i++) {
		buf[i] = 0xffffffff;
	}
}

unsigned int *read_img(int fd, int w, int h) {
	t_bmp_dib	dib;
	t_bmp_head	head;
	unsigned int *buf = malloc(w * h * 4);
	if (read(fd, &head, sizeof(t_bmp_head)) < sizeof(t_bmp_head)) {
		set_img(buf, w, h);
		return (buf);
	}
	read(fd, &dib, sizeof(dib));
	read(fd, buf, head.size - head.offset);
	return (buf);
}

void fill_img(unsigned int *buf, int x, int y, unsigned int col)
{
	y = COLOR_COUNT_ROW - 1 - y;
	for (int i = x * COLOR_SIZE; i < (x + 1) * COLOR_SIZE; i++) {
		for (int j = y * COLOR_SIZE; j < (y + 1) * COLOR_SIZE; j++) {
			buf[i + j * COLOR_SIZE * COLOR_COUNT_ROW] = col;
		}
	}
}

void		create_bmp(char *bmp, int x, int y, unsigned int col)
{
	int			fd;
	t_env		*e = env();
	t_bmp_dib	dib_header;
	t_bmp_head	bmp_header;

	if (!(fd = open(bmp, O_CREAT | O_RDONLY, 0766)))
		exit(-1);
	e->buf = read_img(fd, e->w, e->h);
	close(fd);
	if (!(fd = open(bmp, O_WRONLY | O_TRUNC, 0766)))
		exit(-1);
	bmp_header = head(e->w, e->h);
	write(fd, &bmp_header, 14);
	dib_header = dib(e->w, e->h);
	write(fd, &dib_header, dib_header.self_size);
	fill_img(e->buf, x, y, col);
	write(fd, e->buf, e->w * e->h * 32);
	close(fd);
	free(e->buf);
	exit(0);
}
