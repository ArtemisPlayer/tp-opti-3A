#include <omp.h>

void light(int w, int h, unsigned char *img, unsigned char val)
{
	int i,j;
	unsigned char current;
	#pragma omp parallel for
	for (i = 0; i < w; i++) {
		for (j = 0; j < h; j++) {
			current = img[j * w + i];
			img[j * w + i] = (((int) current + val) > 255) ? 255 : current + val;
		}
	}
}

void curve(int w, int h, unsigned char *img, unsigned char *lut)
{
	int i,j;
  	unsigned char current;
	#pragma omp parallel for
  	for (i = 0; i < w; i++) {
  		for (j = 0; j < h; j++) {
  			current = img[j * w + i];
			img[j * w + i] = lut[current];
  		}
  	}
}

void transfo(int w, int h, unsigned char *src, unsigned char *lut, unsigned char val)
{
  	curve(w, h, src, lut);
  	light(w, h, src, val);
}
