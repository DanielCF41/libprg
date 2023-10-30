#include <libprg/libprg.h>

void inicio(struct timeval *inicio){
    gettimeofday(inicio, 0);
}

double finaliza(struct timeval *inicio){
    struct timeval fim;
    gettimeofday(&fim, 0);
    long seg = fim.tv_sec - inicio->tv_sec;
    long mseg = fim.tv_usec - inicio->tv_usec;
    return seg + mseg * 1e-6;
}

double finaliza_cpu(clock_t start){
    clock_t end = clock();
    return  ((double) (end - start)) / CLOCKS_PER_SEC;
}



