#include <assert.h>
#include <math.h>
#include <float.h>
#include <stdio.h>

#include "../random/random.h"
#include "vec2.h"
#include "../src/mathlib/vec2.h"


vec2 vec2_rand()
{
    return (vec2) {
        .e1 = double_rand(),
        .e2 = double_rand(),
    };
}

void test_vec2_dot_product()
{
    {
        vec2 a = {1, 1};
        vec2 b = {2, 2};
        double c = vec2_dot_product(&a, &b);
        assert( c == 4.0 );
    }
    
    {
        vec2 a = vec2_rand();
        vec2 b = vec2_rand();
        double c = vec2_dot_product(&a, &b);
        double d = a.e1 * b.e1 + a.e2 * b.e2;
        assert( c == d );
    }

    {
        vec2 a = {0, 0};
        vec2 b = {3, 4};
        double c = vec2_dot_product(&a, &b);
        assert( c == 0 );
    }

    {
        vec2 a = {-3, -4};
        vec2 b = {3, 4};
        double c = vec2_dot_product(&a, &b);
        assert( c == -25 );
    }
}

void test_vec2_self_dot_product()
{
    {
        vec2 a = {1, 1};
        double c = vec2_self_dot_product(&a);
        assert( c == 2 );
    }
    
    {
        vec2 a = vec2_rand();
        double c = vec2_self_dot_product(&a);
        double d = a.e1 * a.e1 + a.e2 * a.e2;
        assert( c == d );
    }

    {
        vec2 a = {0, 0};
        double b = vec2_self_dot_product(&a); 
        assert( b == 0 );
    }
}

void test_vec2_module()
{
    {
        vec2 a = {3, 2};
        double b = vec2_module(&a);
        double c = sqrt(3*3 + 2*2);
        assert( b == c );
    }
    
    {
        vec2 a = vec2_rand();
        double b = vec2_module(&a);
        double c = sqrt(a.e1 * a.e1 + a.e2 * a.e2);
        assert( b == c );
    }

    {
        vec2 a = {0, 0};
        double b = vec2_module(&a);
        assert( b == 0 );
    }
}

void test_vec2_scale()
{
    {
        vec2 a = {3, 5};
        double b = 1.5;
        vec2 c = vec2_scale(&a, b);
        assert( c.e1 == a.e1 * b );
        assert( c.e2 == a.e2 * b );
    }
    
    {
        vec2 a = vec2_rand();
        double b = double_rand();
        vec2 c = vec2_scale(&a, b);
        assert( c.e1 == a.e1 * b );
        assert( c.e2 == a.e2 * b );
    }

    {
        vec2 a = {3, 4};
        vec2 b = vec2_scale(&a, 0);
        assert( b.e1 == 0 );
        assert( b.e2 == 0 );
    }

    {
        vec2 a = vec2_rand();
        vec2 b = vec2_scale(&a, -1);
        assert( b.e1 == -a.e1 );
        assert( b.e2 == -a.e2 );
    }
}

void test_vec2_scale_in_place()
{
    {
        vec2 a = {3, 5};
        double b = 1.5;
        vec2_scale_in_place(&a, b);
        assert( a.e1 == 3 * 1.5 );
        assert( a.e2 == 5 * 1.5 );
    }
    
    {
        vec2 a = vec2_rand();
        double b = double_rand();
        vec2 c = { a.e1 * b, a.e2 * b };
        vec2_scale_in_place(&a, b);
        assert( a.e1 == c.e1 );
        assert( a.e2 == c.e2 );
    }

    {
        vec2 a = {3, 4};
        vec2_scale_in_place(&a, 0);
        assert( a.e1 == 0 );
        assert( a.e2 == 0 );
    }
    
    {
        vec2 a = vec2_rand();
        vec2_scale_in_place(&a, 0);
        assert( a.e1 == 0 );
        assert( a.e2 == 0 );
    }

    {
        vec2 a = {3, 4};
        vec2_scale_in_place(&a, -1);
        assert( a.e1 == -3 );
        assert( a.e2 == -4 );
    }
    
    {
        vec2 a = vec2_rand();
        vec2 b = {a.e1, a.e2};
        double c = double_rand();
        vec2_scale_in_place(&a, -c);
        // TODO: vec2 vec2_copy()
        assert( a.e1 == b.e1 * -c);
        assert( a.e2 == b.e2 * -c);
    }
}

void test_vec2_normalize()
{
    {
        vec2 a = {3, 4};
        vec2 b = vec2_normalize(&a);
        double c = vec2_module(&b);
        assert( (c - 1.0) < DBL_MIN ); // TODO: Could use DBL_TRUE_MIN but GePeTo says that is a subnormal number XD
    }

    // TODO: vec2_normalize({0, 0}), no se si comprobar que el vec2 no sea {0, 0} en la libreria

    {
        vec2 a = vec2_rand();
        vec2 b = vec2_normalize(&a);
        double c = vec2_module(&b);
        assert( (c - 1.0) < DBL_MIN ); // TODO: Could use DBL_TRUE_MIN but GePeTo says that is a subnormal number XD
    }
}

void test_vec2_normalize_in_place()
{
    {
        vec2 a = {3, 4};
        vec2_normalize_in_place(&a);
        double c = vec2_module(&a);
        assert( (c - 1.0) < DBL_MIN ); // TODO: Could use DBL_TRUE_MIN but GePeTo says that is a subnormal number XD
    }

    // TODO: vec2_normalize({0, 0}), no se si comprobar que el vec2 no sea {0, 0} en la libreria

    {
        vec2 a = vec2_rand();
        vec2_normalize_in_place(&a);
        double c = vec2_module(&a);
        assert( (c - 1.0) < DBL_MIN ); // TODO: Could use DBL_TRUE_MIN but GePeTo says that is a subnormal number XD
    }
}

void test_vec2_sum()
{
    {
        vec2 a = {1, 2};
        vec2 b = {3, 4};
        vec2 c = vec2_sum(&a, &b);
        assert( c.e1 == 4 );
        assert( c.e2 == 6 );
    }

    {
        vec2 a = {0, 0};
        vec2 b = {3, 4};
        vec2 c = vec2_sum(&a, &b);
        assert( c.e1 == 3 );
        assert( c.e2 == 4 );
    }
    
    {
        vec2 a = vec2_rand();
        vec2 b = vec2_rand();
        vec2 c = vec2_sum(&a, &b);
        assert( c.e1 == a.e1 + b.e1 );
        assert( c.e2 == a.e2 + b.e2 );
    }
}

void test_vec2_sum_in_place()
{
    {
        vec2 a = {1, 2};
        vec2 b = {3, 4};
        vec2_sum_in_place(&a, &b);
        assert( a.e1 == 4 );
        assert( a.e2 == 6 );
    }

    {
        vec2 a = {0, 0};
        vec2 b = {3, 4};
        vec2_sum_in_place(&a, &b);
        assert( a.e1 == 3 );
        assert( a.e2 == 4 );
    }
    
    {
        vec2 a = vec2_rand();
        vec2 b = vec2_rand();
        vec2 c = {a.e1, a.e2};
        vec2_sum_in_place(&a, &b);
        assert( a.e1 == c.e1 + b.e1 );
        assert( a.e2 == c.e2 + b.e2 );
    }
}


void test_vec2_subtract()
{
    {
        vec2 a = {1, 2};
        vec2 b = {3, 4};
        vec2 c = vec2_subtract(&a, &b);
        assert( c.e1 == -2 );
        assert( c.e2 == -2 );
    }

    {
        vec2 a = {0, 0};
        vec2 b = {3, 4};
        vec2 c = vec2_subtract(&a, &b);
        assert( c.e1 == -3 );
        assert( c.e2 == -4 );
    }
    
    {
        vec2 a = vec2_rand();
        vec2 b = vec2_rand();
        vec2 c = vec2_subtract(&a, &b);
        assert( c.e1 == a.e1 - b.e1 );
        assert( c.e2 == a.e2 - b.e2 );
    }
}

void test_vec2_subtract_in_place()
{
    {
        vec2 a = {1, 2};
        vec2 b = {3, 4};
        vec2_subtract_in_place(&a, &b);
        assert( a.e1 == -2 );
        assert( a.e2 == -2 );
    }

    {
        vec2 a = {0, 0};
        vec2 b = {3, 4};
        vec2_subtract_in_place(&a, &b);
        assert( a.e1 == -3 );
        assert( a.e2 == -4 );
    }
    
    {
        vec2 a = vec2_rand();
        vec2 b = vec2_rand();
        vec2 c = {a.e1, a.e2};
        vec2_subtract_in_place(&a, &b);
        assert( a.e1 == c.e1 - b.e1 );
        assert( a.e2 == c.e2 - b.e2 );
    }
}

void vec2_test()
{
    test_vec2_dot_product();
    test_vec2_self_dot_product();
    test_vec2_module();
    test_vec2_scale();
    test_vec2_scale_in_place();
    test_vec2_normalize();
    test_vec2_normalize_in_place();
    test_vec2_sum();
    test_vec2_sum_in_place();
    test_vec2_subtract();
    test_vec2_subtract_in_place();

    printf("test_vec2 OK\n");
}
