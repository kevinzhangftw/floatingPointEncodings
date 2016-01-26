//
//  main.c
//  floatingPointEncodings
//
//  Created by Kai Zhang on 2016-01-25.
//  Copyright © 2016 Kai Zhang. All rights reserved.
//

#include <stdio.h>
#include "fplib.h"


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    
    bit16 someFloat = float_16(1, 100000, 1100000); //supposed to be -2^(1) * 1.75
    
    
    return 0;
}
