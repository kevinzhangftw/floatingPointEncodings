//
//  fplib.h
//  floatingPointEncodings
//
//  Created by Kai Zhang on 2016-01-25.
//  Copyright © 2016 Kai Zhang. All rights reserved.
//

#ifndef fplib_h
#define fplib_h

#include <stdio.h>

typedef unsigned int bit16;//FP(16, 8)
struct signExpFrac {
    unsigned sign;
    unsigned exp;
    unsigned frac;
};

struct signExpFrac extract(bit16 x);

bit16 float_16(unsigned sign, unsigned exp, unsigned frac);

bit16 fp_mult(bit16 x, bit16 y);



#endif /* fplib_h */
