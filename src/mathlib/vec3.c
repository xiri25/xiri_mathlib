#include <math.h>
#include "vec3.h"

double vec3_dot_product(const vec3* a, const vec3* b)
{
    return a->e1 * b->e1 + a->e2 * b->e2 + a->e3 * b->e3;
}

double vec3_self_dot_product(const vec3* a)
{
    return a->e1 * a->e1 + a->e2 * a->e2 + a->e3 * a->e3;
}

double vec3_module(const vec3* a)
{
    return(sqrt(vec3_self_dot_product(a)));
}

vec3 vec3_scale(const vec3* a, const double b)
{
    return (vec3) {
        .e1 = a->e1 * b,
        .e2 = a->e2 * b,
        .e3 = a->e3 * b,
    };
}

void vec3_scale_in_place(vec3* out, const double a)
{
    out->e1 *= a;
    out->e2 *= a;
    out->e3 *= a;
}

vec3 vec3_normalize(const vec3* a)
{
    double mod = vec3_module(a);
    double mod_inv = 1.0 / mod;
    return vec3_scale(a, mod_inv);
}

void vec3_normalize_in_place(vec3* out)
{
    double mod  = vec3_module(out);
    double mod_inv = 1.0 / mod;
    vec3_scale_in_place(out, mod_inv);
}

vec3 vec3_sum(const vec3* a, const vec3* b)
{
    return (vec3) {
        .e1 = a->e1 + b->e1,
        .e2 = a->e2 + b->e2,
        .e3 = a->e3 + b->e3,
    };
}

void vec3_sum_in_place(vec3* out, const vec3* a)
{
    out->e1 += a->e1;
    out->e2 += a->e2;
    out->e3 += a->e3;
}

vec3 vec3_subtract(const vec3* a, const vec3* b)
{
    return (vec3) {
        .e1 = a->e1 - b->e1,
        .e2 = a->e2 - b->e2,
        .e3 = a->e3 - b->e3,
    };
}

void vec3_subtract_in_place(vec3* out, const vec3* a)
{
    out->e1 -= a->e1;
    out->e2 -= a->e2;
    out->e3 -= a->e3;
}

vec3 vec3_cross_product(vec3* a, vec3* b)
{
    /*
     * | i  j  k|
     * |a1 a2 a3|
     * |b1 b2 b3|
    */
    return (vec3) {
        .e1 = a->e2 * b->e3 - a->e3 * b->e2,
        .e2 = -(a->e1 * b->e3 - a->e3 * b->e1),
        .e3 = a->e1 * b->e2 - a->e2 * b->e1,
    };
}
