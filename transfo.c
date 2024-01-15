#include <omp.h>

void transfo(int w, int h, unsigned char *img, unsigned char *lut, unsigned char val)
{
  	#pragma omp parallel for collapse(2)
	for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            unsigned char result;
            unsigned char pixel = lut[img[j * w + i]]; // curve effect

            asm volatile (
                "mov %1, %%al\n"
                "add %2, %%al\n"
                "jnc no_overflow_%=\n"
                "mov $255, %%al\n"
                "no_overflow_%=:"
                : "=a" (result)
                : "g" (pixel), "g" (val)
            ); 

            img[j * w + i] = result;
        }
    }
}
