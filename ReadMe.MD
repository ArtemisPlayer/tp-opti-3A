To compile & run:
```
gcc io.c cycles.c transfo.c -o transform_image -fopenmp -Ofast -ftree-vectorize -march=native -fvect-cost-model=very-cheap && ./transform_image data/transfo.txt
```

History:
* Removed useless array copy: 50%
* Used OpenMP: 9.5%
* Used assembly overflow check: 8.8% 
* Merged loops & removed functions: 4.8%
* Compiler args: 4.1%

Other tests that were not successful:
* Overclocking CPU does improve time but not cpu cycles