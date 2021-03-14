
#ifndef PALETTE_IMAGE_H
#define PALETTE_IMAGE_H

#define COLOR_COUNT_ROW		16
#define COLOR_SIZE			16

#include "bmp.h"

typedef struct	s_env {
	int				w;
	int				h;
	unsigned int	*buf;
}				t_env;

void		create_bmp(char *bmp, int x, int y, unsigned int col);

#endif
