To compile & run:
```
gcc io.c cycles.c transfo.c -o transform_image
./transform_image data/transfo.txt
```

History:
* Removed useless array copy: 50%
* Used OpenMP: 9.5%
* Used assembly overflow check: 8.8% 
* Merged loops & removed functions: 4.8%