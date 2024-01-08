#include <omp.h>

void light(int w, int h, unsigned char *img, unsigned char val)
{
	#pragma omp parallel for collapse(2)
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			if ((img[j * w + i] + val) > 255) {
				img[j * w + i] =  255;
			} else {
				img[j * w + i] = img[j * w + i] + val;
			}
		}
	}
}

void curve(int w, int h, unsigned char *img, unsigned char *lut)
{
	int i,j;
	#pragma omp parallel for collapse(2)
  	for (i = 0; i < w; i++) {
  		for (j = 0; j < h; j++) {
			img[j * w + i] = lut[img[j * w + i]];
  		}
  	}
}

void transfo(int w, int h, unsigned char *src, unsigned char *lut, unsigned char val)
{
  	curve(w, h, src, lut);
  	light(w, h, src, val);
}
