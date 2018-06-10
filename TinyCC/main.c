//
//  main.c
//  tccproject
//
//  Created by eddy.wu on 11/24/17.
//  Copyright © 2017 eddy.wu. All rights reserved.
//

#include <stdio.h>

#include "tcc.h"
#include "libtcc.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    TCCState *s;
    int ret, optind, i, bench;
    int64_t start_time = 0;
    const char *first_file = NULL;
    
    s = tcc_new();
    s->output_type = TCC_OUTPUT_EXE;
    
    printf("%d\n",s->output_type);
    
    //printf("test\n");
    
    return 0;
}
