#include "../random/random.h"
#include "vec2.h"
#include "vec3.h"

int main(void)
{
    rand_init();

    vec2_test();
    vec3_test();
}
