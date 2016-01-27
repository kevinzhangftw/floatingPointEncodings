//
//  fplib.c
//  floatingPointEncodings
//
//  Created by Kai Zhang on 2016-01-25.
//  Copyright © 2016 Kai Zhang. All rights reserved.
//

#include "fplib.h"
#include <math.h>
#include <assert.h> 

struct signExpFrac extract(bit16 x){
    struct signExpFrac newSignExpFrac;
    //implementation here
    return newSignExpFrac;
}

int binary_decimal(int n) {
    int decimal=0, i=0, rem;
    while (n!=0)
    {
        rem = n%10;
        n/=10;
        decimal += rem*pow(2,i);
        ++i;
    }
    return decimal;
}

int power(int base, unsigned int exp) {
    int i, result = 1;
    for (i = 0; i < exp; i++)
        result *= base;
    return result;
}
/// 1 sign, 7 exponents, 8 fraction
bit16 float_16(unsigned sign, unsigned exp, unsigned frac){

    assert(sign == 1 || sign == 0);
    assert(exp >= 0 && exp < power(2, 7));
    assert(frac >= 0 && frac < power(2, 8));
    
    bit16 combined;
    combined += sign * power(2, 15);
    combined += exp * power(2, 7);
    combined += frac;
    
    return combined;
}

bit16 fp_mult(bit16 x, bit16 y){
    bit16 product;
    //implementation here
    return product;
}