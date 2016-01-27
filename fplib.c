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


unsigned int multiplyFracComponents(unsigned int leftFrac, unsigned int rightFrac) {
    //TODO:
    
    return 0;
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
    combined += exp * power(2, 8);
    combined += frac;
    //legit.
    return combined;
}


struct signExpFrac extract(bit16 bits){
    assert(bits >= 0 || bits < power(2, 16));
    struct signExpFrac newSignExpFrac;
    
    
    unsigned int signBit = bits / power(2, 15);
    unsigned int exponentBit = (bits % power(2, 15)) / power(2, 8);
    unsigned int fractionBit = bits % power(2, 8);
    
    newSignExpFrac.sign = signBit;
    newSignExpFrac.frac = fractionBit;
    newSignExpFrac.exp = exponentBit;
    
    return newSignExpFrac;
}

bit16 fp_mult(bit16 x, bit16 y){
    bit16 product;
    
    assert(x >= 0 || x < power(2, 16));
    assert(y >= 0 || y < power(2, 16));
    
    struct signExpFrac multipliedComponents;
    
    struct signExpFrac xComponents = extract(x);
    struct signExpFrac yComponents = extract(y);
    
    multipliedComponents.sign = xComponents.sign * yComponents.sign;

    unsigned int multipliedExponent = xComponents.exp + yComponents.exp;
    if (multipliedExponent > power(2, 7)) { //overflow exponents
        assert(multipliedExponent < power(2, 7)); //TODO: check later.
    }
    multipliedComponents.exp = multipliedExponent;
    
    
    
    unsigned int multipliedFraction = multiplyFracComponents(xComponents.frac, yComponents.frac);
    if (multipliedFraction >= power(2, 8)) {
        //TODO: carry over to the exponent
        assert(multipliedFraction < power(2, 8));
    } else {
        //business as usual. no carry over.
        
    }
    
    
    
    return product;
}



