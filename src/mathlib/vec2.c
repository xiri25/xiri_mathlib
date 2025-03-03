#include <math.h>
#include "vec2.h"

double vec2_dot_product(const vec2* a, const vec2* b)
{
    return a->e1 * b->e1 + a->e2 * b->e2;
}

double vec2_self_dot_product(const vec2* a)
{
    return a->e1 * a->e1 + a->e2 * a->e2;
}

double vec2_module(const vec2* a)
{
    return(sqrt(vec2_self_dot_product(a)));
}

vec2 vec2_scale(const vec2* a, const double b)
{
    return (vec2) {
        .e1 = a->e1 * b,
        .e2 = a->e2 * b,
    };
}

void vec2_scale_in_place(vec2* out, const double a)
{
    out->e1 *= a;
    out->e2 *= a;
}

vec2 vec2_normalize(const vec2* a)
{
    double mod = vec2_module(a);
    double mod_inv = 1.0 / mod;
    return vec2_scale(a, mod_inv);
}

void vec2_normalize_in_place(vec2* out)
{
    double mod  = vec2_module(out);
    double mod_inv = 1.0 / mod;
    vec2_scale_in_place(out, mod_inv);
}

vec2 vec2_sum(const vec2* a, const vec2* b)
{
    return (vec2) {
        .e1 = a->e1 + b->e1,
        .e2 = a->e2 + b->e2,
    };
}

void vec2_sum_in_place(vec2* out, const vec2* a)
{
    out->e1 += a->e1;
    out->e2 += a->e2;
}

vec2 vec2_subtract(const vec2* a, const vec2* b)
{
    return (vec2) {
        .e1 = a->e1 - b->e1,
        .e2 = a->e2 - b->e2,
    };
}

void vec2_subtract_in_place(vec2* out, const vec2* a)
{
    out->e1 -= a->e1;
    out->e2 -= a->e2;
}

