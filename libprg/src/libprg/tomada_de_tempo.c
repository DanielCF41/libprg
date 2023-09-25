#include <libprg/libprg.h>

void incio_tempo(){
    gettimeofday(&inicio, 0);
}

int fim_tempo(){
    gettimeofday(&fim, 0);

    long seg = fim.tv_sec - inicio.tv_sec;
    long mseg = fim.tv_usec - inicio.tv_usec;
    double tempo_total = seg + mseg * 1e-6;

    return tempo_total;
}