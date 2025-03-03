#ifndef VEC3_H
#define VEC3_H

typedef struct {
    double e1;
    double e2;
    double e3;
} vec3;

double vec3_dot_product(const vec3* a, const vec3* b);
double vec3_self_dot_product(const vec3* a);
double vec3_module(const vec3* a);
vec3 vec3_scale(const vec3* a, const double b);
void vec3_scale_in_place(vec3* out, const double a);
vec3 vec3_normalize(const vec3* a);
void vec3_normalize_in_place(vec3* out);
vec3 vec3_sum(const vec3* a, const vec3* b);
void vec3_sum_in_place(vec3* out, const vec3* a);
vec3 vec3_subtract(const vec3* a, const vec3* b);
void vec3_subtract_in_place(vec3* out, const vec3* a);
vec3 vec3_cross_product(vec3* a, vec3* b);

#endif // !VEC3_H
