
#include "image.h"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int x = strtol(av[1], NULL, 10);
	int y = strtol(av[2], NULL, 10);
	int col = strtol(av[3], NULL, 16);
	create_bmp("palette.bmp", x, y, col);
}

