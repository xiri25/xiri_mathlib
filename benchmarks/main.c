#include "../src/mathlib/vec3.h"
#include "../random/random.h"

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

double time_now_ms(void) {
  struct timespec current_time;
  clock_gettime(CLOCK_MONOTONIC_RAW, &current_time);
  return current_time.tv_sec * 1000 + (current_time.tv_nsec / 1e6);
}

vec3 vec3_rand(void)
{
    return (vec3) {
        .e1 = double_rand(),
        .e2 = double_rand(),
        .e3 = double_rand(),
    };
}

vec3* generate_vec3_array(size_t count)
{
    vec3* array = malloc(sizeof(vec3) * count);
    for (size_t i = 0; i < count; i++) {
        array[i] = vec3_rand();
    }
    
    return array;
}

void vec3_print(vec3 a)
{
    printf("vec3(%.5e, %.5e, %.5e)\n", a.e1, a.e2, a.e3);
}

int main(void)
{
    rand_init();

    uint32_t vec3_array_len = 10000000;
    vec3* vec3_array = generate_vec3_array(vec3_array_len);


    vec3 sumando = vec3_rand();
    vec3 sumando2 = sumando;
    {
        printf("Benchmark vec3_sum\n");

        double time_start = time_now_ms();
        for (uint32_t i = 0; i < vec3_array_len; i++) {
            sumando = vec3_sum(&sumando, &vec3_array[i]);
        }
        double time_stop = time_now_ms();

        vec3_print(sumando);

        double time = time_stop - time_start;
        double time_avg = time / vec3_array_len;

        printf("Time = %.5ems, Time_avg = %.5ems, Time_avg = %.5ens\n", time, time_avg, time_avg * 1e6);
        /* time_avg * 1e6 * (cpu GHz) should be close to the number of cycles */
        printf("\n");
    }
    
    {
        printf("Benchmark vec3_sum_in_place\n");

        double time_start = time_now_ms();
        for (uint32_t i = 0; i < vec3_array_len; i++) {
            vec3_sum_in_place(&sumando2, &vec3_array[i]);
        }
        double time_stop = time_now_ms();

        vec3_print(sumando2);

        double time = time_stop - time_start;
        double time_avg = time / vec3_array_len;

        printf("Time = %.5ems, Time_avg = %.5ems, Time_avg = %.5ens\n", time, time_avg, time_avg * 1e6);
        printf("\n");
    }


    printf("\n");
    free(vec3_array);
    return 0;
}
