#ifndef VEC2_H
#define VEC2_H

typedef struct {
    double e1;
    double e2;
} vec2;

double vec2_dot_product(const vec2* a, const vec2* b);
double vec2_self_dot_product(const vec2* a);
double vec2_module(const vec2* a);
vec2 vec2_scale(const vec2* a, const double b);
void vec2_scale_in_place(vec2* out, const double a);
vec2 vec2_normalize(const vec2* a);
void vec2_normalize_in_place(vec2* out);
vec2 vec2_sum(const vec2* a, const vec2* b);
void vec2_sum_in_place(vec2* out, const vec2* a);
vec2 vec2_subtract(const vec2* a, const vec2* b);
void vec2_subtract_in_place(vec2* out, const vec2* a);

#endif // !VEC2_H
