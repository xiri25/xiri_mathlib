#include <assert.h>
#include <math.h>
#include <float.h>
#include <stdio.h>

#include "../random/random.h"
#include "vec3.h"
#include "../src/mathlib/vec3.h"

#define EPSILON 1e-6


vec3 vec3_rand()
{
    return (vec3) {
        .e1 = double_rand(),
        .e2 = double_rand(),
        .e3 = double_rand(),
    };
}

void test_vec3_dot_product()
{
    {
        vec3 a = {1, 1, 3};
        vec3 b = {2, 2, 5};
        double c = vec3_dot_product(&a, &b);
        assert( c == 19.00 );
    }
    
    {
        vec3 a = vec3_rand();
        vec3 b = vec3_rand();
        double c = vec3_dot_product(&a, &b);
        double d = a.e1 * b.e1 + a.e2 * b.e2 + a.e3 * b.e3;
        assert( c == d );
    }

    {
        vec3 a = {0, 0, 0};
        vec3 b = {3, 4, 5};
        double c = vec3_dot_product(&a, &b);
        assert( c == 0 );
    }

    {
        vec3 a = {-3, -4, -5};
        vec3 b = {3, 4, -5};
        double c = vec3_dot_product(&a, &b);
        assert( c == 0.0 );
    }
}

void test_vec3_self_dot_product()
{
    {
        vec3 a = {1, 1, 1};
        double c = vec3_self_dot_product(&a);
        assert( c == 3 );
    }
    
    {
        vec3 a = vec3_rand();
        double c = vec3_self_dot_product(&a);
        double d = a.e1 * a.e1 + a.e2 * a.e2 + a.e3 * a.e3;
        assert( c == d );
    }

    {
        vec3 a = {0, 0, 0};
        double b = vec3_self_dot_product(&a); 
        assert( b == 0 );
    }
}

void test_vec3_module()
{
    {
        vec3 a = {3, 2, 1};
        double b = vec3_module(&a);
        double c = sqrt(3*3 + 2*2 + 1*1);
        assert( b == c );
    }
    
    {
        vec3 a = vec3_rand();
        double b = vec3_module(&a);
        double c = sqrt(a.e1 * a.e1 + a.e2 * a.e2 + a.e3 * a.e3);
        assert( b == c );
    }

    {
        vec3 a = {0, 0, 0};
        double b = vec3_module(&a);
        assert( b == 0 );
    }
}

void test_vec3_scale()
{
    {
        vec3 a = {3, 5, 4};
        double b = 1.5;
        vec3 c = vec3_scale(&a, b);
        assert( c.e1 == a.e1 * b );
        assert( c.e2 == a.e2 * b );
        assert( c.e3 == a.e3 * b );
    }
    
    {
        vec3 a = vec3_rand();
        double b = double_rand();
        vec3 c = vec3_scale(&a, b);
        assert( c.e1 == a.e1 * b );
        assert( c.e2 == a.e2 * b );
        assert( c.e3 == a.e3 * b );
    }

    {
        vec3 a = {3, 4, 0};
        vec3 b = vec3_scale(&a, 0);
        assert( b.e1 == 0 );
        assert( b.e2 == 0 );
        assert( b.e3 == 0 );
    }

    {
        vec3 a = vec3_rand();
        vec3 b = vec3_scale(&a, -1);
        assert( b.e1 == -a.e1 );
        assert( b.e2 == -a.e2 );
        assert( b.e3 == -a.e3 );
    }
}

void test_vec3_scale_in_place()
{
    {
        vec3 a = {3, 5, 10};
        double b = 1.5;
        vec3_scale_in_place(&a, b);
        assert( a.e1 == 3 * 1.5 );
        assert( a.e2 == 5 * 1.5 );
        assert( a.e3 == 10 * 1.5 );
    }
    
    {
        vec3 a = vec3_rand();
        double b = double_rand();
        vec3 c = { a.e1 * b, a.e2 * b, a.e3 * b };
        vec3_scale_in_place(&a, b);
        assert( a.e1 == c.e1 );
        assert( a.e2 == c.e2 );
        assert( a.e3 == c.e3 );
    }

    {
        vec3 a = {3, 4, 0};
        vec3_scale_in_place(&a, 0);
        assert( a.e1 == 0 );
        assert( a.e2 == 0 );
        assert( a.e3 == 0 );
    }
    
    {
        vec3 a = vec3_rand();
        vec3_scale_in_place(&a, 0);
        assert( a.e1 == 0 );
        assert( a.e2 == 0 );
        assert( a.e3 == 0 );
    }

    {
        vec3 a = {3, 4, 0};
        vec3_scale_in_place(&a, -1);
        assert( a.e1 == -3 );
        assert( a.e2 == -4 );
        assert( a.e3 == 0 );
    }
    
    {
        vec3 a = vec3_rand();
        vec3 b = {a.e1, a.e2, a.e3};
        double c = double_rand();
        vec3_scale_in_place(&a, -c);
        // TODO: vec3 vec3_copy()
        assert( a.e1 == b.e1 * -c);
        assert( a.e2 == b.e2 * -c);
        assert( a.e3 == b.e3 * -c);
    }
}

void test_vec3_normalize()
{
    {
        vec3 a = {3, 4, 9};
        vec3 b = vec3_normalize(&a);
        double c = vec3_module(&b);
        //printf("c = %f, espected_c = 1\n", c);
        assert( fabs((c - 1.0)) < EPSILON ); // TODO: Could use DBL_TRUE_MIN but GePeTo says that is a subnormal number XD
    }

    // TODO: vec2_normalize({0, 0}), no se si comprobar que el vec2 no sea {0, 0} en la libreria

    {
        vec3 a = vec3_rand();
        vec3 b = vec3_normalize(&a);
        double c = vec3_module(&b);
        //printf("c = %f, espected_c = 1\n", c);
        assert( fabs((c - 1.0)) < EPSILON ); // TODO: Could use DBL_TRUE_MIN but GePeTo says that is a subnormal number XD
    }
}

void test_vec3_normalize_in_place()
{
    {
        vec3 a = {3, 4, 1};
        vec3_normalize_in_place(&a);
        double c = vec3_module(&a);
        //printf("c = %f, espected_c = 1\n", c);
        assert( fabs((c - 1.0)) < EPSILON ); // TODO: Could use DBL_TRUE_MIN but GePeTo says that is a subnormal number XD
    }

    // TODO: vec2_normalize({0, 0}), no se si comprobar que el vec2 no sea {0, 0} en la libreria

    {
        vec3 a = vec3_rand();
        vec3_normalize_in_place(&a);
        double c = vec3_module(&a);
        //printf("c = %f, espected_c = 1\n", c);
        assert( fabs((c - 1.0)) < EPSILON ); // TODO: Could use DBL_TRUE_MIN but GePeTo says that is a subnormal number XD
    }
}

void test_vec3_sum()
{
    {
        vec3 a = {1, 2, 4};
        vec3 b = {3, 4, 0};
        vec3 c = vec3_sum(&a, &b);
        assert( c.e1 == 4 );
        assert( c.e2 == 6 );
        assert( c.e3 == 4 );
    }

    {
        vec3 a = {0, 0, 0};
        vec3 b = {3, 4, 1};
        vec3 c = vec3_sum(&a, &b);
        assert( c.e1 == 3 );
        assert( c.e2 == 4 );
        assert( c.e3 == 1 );
    }
    
    {
        vec3 a = vec3_rand();
        vec3 b = vec3_rand();
        vec3 c = vec3_sum(&a, &b);
        assert( c.e1 == a.e1 + b.e1 );
        assert( c.e2 == a.e2 + b.e2 );
        assert( c.e3 == a.e3 + b.e3 );
    }
}

void test_vec3_sum_in_place()
{
    {
        vec3 a = {1, 2, 5};
        vec3 b = {3, 4, 6};
        vec3_sum_in_place(&a, &b);
        assert( a.e1 == 4 );
        assert( a.e2 == 6 );
        assert( a.e3 == 11 );
    }

    {
        vec3 a = {0, 0, 0};
        vec3 b = {3, 4, 5};
        vec3_sum_in_place(&a, &b);
        assert( a.e1 == 3 );
        assert( a.e2 == 4 );
        assert( a.e3 == 5 );
    }
    
    {
        vec3 a = vec3_rand();
        vec3 b = vec3_rand();
        vec3 c = {a.e1, a.e2, a.e3};
        vec3_sum_in_place(&a, &b);
        assert( a.e1 == c.e1 + b.e1 );
        assert( a.e2 == c.e2 + b.e2 );
        assert( a.e3 == c.e3 + b.e3 );
    }
}


void test_vec3_subtract()
{
    {
        vec3 a = {1, 2, 6};
        vec3 b = {3, 4, 5};
        vec3 c = vec3_subtract(&a, &b);
        assert( c.e1 == -2 );
        assert( c.e2 == -2 );
        assert( c.e3 == 1 );
    }

    {
        vec3 a = {0, 0, 0.0};
        vec3 b = {3, 4, 0.0};
        vec3 c = vec3_subtract(&a, &b);
        assert( c.e1 == -3 );
        assert( c.e2 == -4 );
        assert( c.e3 == 0.0 );
    }
    
    {
        vec3 a = vec3_rand();
        vec3 b = vec3_rand();
        vec3 c = vec3_subtract(&a, &b);
        assert( c.e1 == a.e1 - b.e1 );
        assert( c.e2 == a.e2 - b.e2 );
        assert( c.e3 == a.e3 - b.e3 );
    }
}

void test_vec3_subtract_in_place()
{
    {
        vec3 a = {1, 2, 5};
        vec3 b = {3, 4, 6};
        vec3_subtract_in_place(&a, &b);
        assert( a.e1 == -2 );
        assert( a.e2 == -2 );
        assert( a.e3 == -1 );
    }

    {
        vec3 a = {0, 0, 0.0};
        vec3 b = {3, 4, -1};
        vec3_subtract_in_place(&a, &b);
        assert( a.e1 == -3 );
        assert( a.e2 == -4 );
        assert( a.e3 == 1.0 );
    }
    
    {
        vec3 a = vec3_rand();
        vec3 b = vec3_rand();
        vec3 c = {a.e1, a.e2, a.e3};
        vec3_subtract_in_place(&a, &b);
        assert( a.e1 == c.e1 - b.e1 );
        assert( a.e2 == c.e2 - b.e2 );
        assert( a.e3 == c.e3 - b.e3 );
    }
}

void test_vec3_cross_product()
{
    {
        vec3 a = vec3_rand();
        vec3 b = vec3_rand();
        vec3 c = vec3_cross_product(&a, &b);
        double d = vec3_dot_product(&a, &c);
        double e = vec3_dot_product(&b, &c);
        //printf("d = %f, espected_d = 0\n", d);
        //printf("e = %f, espected_e = 0\n", e);
        assert( fabs(d) < EPSILON );
        assert( fabs(e) < EPSILON );
    }

    // TODO: Vectores paralelos
}

void vec3_test()
{
    test_vec3_dot_product();
    test_vec3_self_dot_product();
    test_vec3_module();
    test_vec3_scale();
    test_vec3_scale_in_place();
    test_vec3_normalize();
    test_vec3_normalize_in_place();
    test_vec3_sum();
    test_vec3_sum_in_place();
    test_vec3_subtract();
    test_vec3_subtract_in_place();
    test_vec3_cross_product();

    printf("test_vec3 OK\n");
}
