#include "random.h"
#include <stdlib.h>

void rand_init()
{
    srand(time(NULL));
}

double double_rand()
{
    return ( (double)rand() / RAND_MAX ) * rand(); // rand[0,1] * rand[0, RAND_MAX]
}
