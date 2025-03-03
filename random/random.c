#include "random.h"
#include <stdlib.h>

void rand_init()
{
    srand(time(NULL));
}

double double_rand()
{
    //Valores mas razonables para evitar overflow
    double max = 1e3;
    double min = -1e3;
    return min + ( (double)rand() / RAND_MAX ) * (max - min); 
}
